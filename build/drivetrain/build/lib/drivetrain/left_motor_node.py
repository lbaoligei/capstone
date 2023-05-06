import rclpy
import RPi.GPIO as GPIO
from rclpy.node import Node
from sensor_msgs.msg import Joy

class Left_motor_node(Node):
    def __init__(self):
        # Initialize the Node with the name 'left_motor_node'
        super().__init__('left_motor_node')
        # Create a subscription to the 'controller_command_dt' topic with the Joy message type
        self.subscription = self.create_subscription(Joy, 'controller_command_dt', self.joy_callback, 10)
        self.subscription

        # Set GPIO pin assignments for motors

        self.left_motor_pwm = 15
        self.left_motor_dir = 19

        # Initialize RPi.GPIO and set GPIO pins as output
        GPIO.setmode(GPIO.BOARD)
        GPIO.setup(self.left_motor_pwm, GPIO.OUT)
        GPIO.setup(self.left_motor_dir, GPIO.OUT)

        # Initialize PWM
        self.left_motor = GPIO.PWM(self.left_motor_pwm, 100)
        self.left_motor.start(0)


    def joy_callback(self, msg):
        # Get the horizontal position of the left joystick (left-right movement)
        left_stick_x = msg.axes[0]
        # Get the vertical position of the left joystick (forward-backward movement)
        left_stick_y = msg.axes[1]

        # Set motor speed to zero initially
        left_speed = 0

        # SET THIS PART TO CHANGE MOTOR SPEED!!
        speed_percentage = 50   # set percentage of duty cycle (from -100 to 100)

        # Check if the joystick is pushed in any of the 4 directions
        # the threshold for triggering moving is |0.98|
        if abs(left_stick_x) > 0.98 or abs(left_stick_y) > 0.98:
            if abs(left_stick_x) > abs(left_stick_y):
                # Left or right movement
                if left_stick_x > 0:
                    # Left movement
                    left_speed = -speed_percentage
                else:
                    # Right movement
                    left_speed = speed_percentage
            else:
                # Front or back movement
                if left_stick_y > 0:
                    # Back movement
                    left_speed = speed_percentage
                else:
                    # Front movement
                    left_speed = -speed_percentage


        self.set_motor_speed(self.left_motor, self.left_motor_dir, left_speed)


    def set_motor_speed(self, motor, dir_pin, speed):
        # Determine the direction of the motor based on the sign of the speed
        direction = 1 if speed >= 0 else 0
        # direction = 0 if speed >= 0 else 1
        # Get the absolute value of the speed
        speed = abs(speed)

        # Set the direction GPIO pin
        GPIO.output(dir_pin, direction)
        # Set the motor PWM duty cycle to control the speed
        motor.ChangeDutyCycle(speed)

    def on_shutdown(self):
        # Stop the motors
        self.left_motor.stop()
        # Clean up GPIO settings
        GPIO.cleanup()


def main(args=None):
    rclpy.init(args=args)
    left_motor_node = Left_motor_node()

    # Register the on_shutdown function to be called when the node is shut down
    print("left_motor_nodeis running ...")

    # Spin the node to keep it running and processing callbacks
    rclpy.spin(left_motor_node)
    rclpy._shutdown(left_motor_node.on_shutdown)    # not sure if this is correct
    # Clean up the node after spinning
    left_motor_node.destroy_node()
    # Shutdown rclpy
    rclpy.shutdown()

if __name__ == '__main__':
    main()
