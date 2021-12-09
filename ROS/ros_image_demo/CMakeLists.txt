cmake_minimum_required(VERSION 3.0.2)
project(ros_image_demo)

set(CMAKE_CXX_STANDARD 11)

# for openCV
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_image_demo
#  CATKIN_DEPENDS cv_bridge image_transport
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(image_pub_node src/image_pub_node.cpp)
target_link_libraries(image_pub_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES})

add_executable(image_sub_node src/image_sub_node.cpp)
target_link_libraries(image_sub_node
        ${catkin_LIBRARIES}
        ${OpenCV_LIBRARIES})
