cmake_minimum_required(VERSION 3.0.2)
project(rosbag_demo)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        rosbag
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(rosbag_write_demo src/rosbag_write.cpp)
target_link_libraries(rosbag_write_demo
        ${catkin_LIBRARIES})

add_executable(rosbag_read_demo src/rosbag_read.cpp)
target_link_libraries(rosbag_read_demo
        ${catkin_LIBRARIES})
