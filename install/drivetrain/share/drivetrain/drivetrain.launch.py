from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
	
    left_motor_node = Node (
        package="drivetrain",
        executable="left_motor_node"
    )
    
    right_motor_node = Node (
        package="drivetrain",
        executable="right_motor_node"
    )
    
    arm_node = Node(
        package="drivetrain",
        executable="arm_node"
    )
    
    controller_node = Node(
        package="drivetrain",
        executable="controller_node"
    )
    
    ld.add_action(left_motor_node)
    ld.add_action(right_motor_node)
    ld.add_action(arm_node)
    ld.add_action(controller_node)
    
    return ld
