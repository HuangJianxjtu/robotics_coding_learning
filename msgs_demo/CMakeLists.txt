cmake_minimum_required(VERSION 2.8.3)
project(msgs_demo)

# new message is dependent on std_msgs and geometry_msgs
find_package(catkin REQUIRED COMPONENTS
    std_msgs
    geometry_msgs
    message_generation  # required by generating the new message
)

add_message_files(FILES demo_msgs.msg)

generate_messages(DEPENDENCIES
    std_msgs
    geometry_msgs
)

catkin_package(CATKIN_DEPENDS
    message_runtime  # required by generating the new message
    std_msgs
    geometry_msgs
)
