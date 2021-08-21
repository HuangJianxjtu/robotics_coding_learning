cmake_minimum_required(VERSION 2.8.3)
project(ros_class_cpp_demo)


find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
)

include_directories(./include)

catkin_package(CATKIN_DEPENDS
        roscpp
        std_msgs
)

add_library(my_class_lib src/myClass.cpp)

add_executable(ros_class_cpp src/main.cpp)
target_link_libraries(ros_class_cpp
        ${catkin_LIBRARIES}
        my_class_lib
)