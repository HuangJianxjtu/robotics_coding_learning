cmake_minimum_required(VERSION 2.8.3)
project(msgs_demo)

# new message is dependent on std_msgs and geometry_msgs
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    geometry_msgs
    message_generation  # required by generating the new message
)

add_message_files(FILES demo_msgs.msg)  #用于自定义消息

generate_messages(DEPENDENCIES  #用于自定义消息
    std_msgs
    geometry_msgs
)

catkin_package(CATKIN_DEPENDS
    roscpp
    rospy
    std_msgs
    geometry_msgs
    message_runtime  # required by generating the new message
)

include_directories(
  ${catkin_INCLUDE_DIRS} #必须加上，否则找不到ros/ros.h
)

# 在cpp中使用自定义的消息类型
add_executable(UseDemoMsg src/useDemoMsg.cpp)
target_link_libraries(UseDemoMsg ${catkin_LIBRARIES})
