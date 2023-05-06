import pygame
import rclpy
from time import sleep
from rclpy.node import Node
from sensor_msgs.msg import Joy

def main(args=None):
    pygame.init()
    pygame.joystick.init()
    controller = pygame.joystick.Joystick(0)
    controller.init()
    button_map = ['x', 'o', 't', 's', 'L1', 'R1', 'L2', 'R2', 'share', 'options',
                  'axis1', 'axis2', 'axis3', 'axis4', 'Dpad up', 'Dpad down', 'Dpad left', 'Dpad right', 'L3', 'R3']

    print("Testing button mapping... Press buttons on the controller to check.")
    try:
        while True:
            for event in pygame.event.get():
                if event.type == pygame.JOYBUTTONDOWN:
                    button = button_map[event.button]
                    print(f"{button} pressed")
                elif event.type == pygame.JOYBUTTONUP:
                    button = button_map[event.button]
                    print(f"{button} released")
            sleep(0.1)
    except KeyboardInterrupt:
        print("Exiting...")
        pygame.quit()

if __name__ == '__main__':
    main()
