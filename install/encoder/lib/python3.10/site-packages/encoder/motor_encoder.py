# We want the motor encoder to count and publish the number of ticks occurring periodically.
# According to those number of ticks we can calculate the number of rotations the motor has done in that time frame.
# Using the rotations amount we can then calculate the distance travelled by the robot.


import rclpy
from rclpy.node import Node
from robot_interfaces.msg import EncoderData 
import RPi.GPIO as GPIO

class MotorEncoder(Node):

    def __init__(self):

        #Initialize Node 
        super().__init__('motor_encoder')
        self.encoder_publisher_ = self.create_publisher(EncoderData, 'encoder_data', 10)
        self.timer_period = 0.1 #encoder_data is published every "self.timer_period" seconds
        self.encoder_timer_ = self.create_timer(self.timer_period, self.publish_encoder)

        #Initialize Value for tracking encoder
        self.encoder_value = 0
        self.last_a = 0
        self.last_b = 0
        self.last_distance = 0

        #Initialize GPIO Input
        self.a_pin = 17 # GPIO Number for Channel A
        self.b_pin = 18 # GPIO Number for Channel B
        GPIO.setmode(GPIO.BCM) # Makes use of GPIO numbers instead of PIN numbers
        GPIO.setup(self.a_pin, GPIO.IN) # Sets A pin as input
        GPIO.setup(self.b_pin, GPIO.IN) # Sets B pin as input
        GPIO.add_event_detect(self.a_pin, GPIO.BOTH, callback = self.a_callback) # Adds detection for when A input changes
        GPIO.add_event_detect(self.b_pin, GPIO.BOTH, callback = self.b_callback) # Adds detection for when B input changes


    def a_callback(self, channel): #Function called when Chnnel A input changes
        a = GPIO.input(self.a_pin)
        b = GPIO.input(self.b_pin)
        if a != self.last_a:
            if a != b:
                self.encoder_value += 1
            else:
                self.encoder_value -= 1
        self.last_a = a
        self.last_b = b

    def b_callback(self, channel): #Function called when Channel B input changes
        a = GPIO.input(self.a_pin)
        b = GPIO.input(self.b_pin)
        if b != self.last_b:
            if a == b:
                self.encoder_value += 1
            else:
                self.encoder_value -= 1
        self.last_a = a
        self.last_b = b

    def publish_encoder(self):
        msg = EncoderData()
        msg.ticks = self.encoder_value
        msg.distance = (0.028 * self.encoder_value) / 1000
        msg.velocity_estimate = (msg.distance - self.last_distance)/self.timer_period
        self.last_distance = msg.distance
        self.encoder_publisher_.publish(msg)



def main(args=None):
    print('motor_encoder is running')
    
    rclpy.init(args=args)
    motor_encoder = MotorEncoder()
    rclpy.spin(motor_encoder)

    motor_encoder.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
