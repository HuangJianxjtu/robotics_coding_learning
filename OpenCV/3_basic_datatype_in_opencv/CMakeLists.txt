cmake_minimum_required(VERSION 3.0.2)
project(opencv_basic_datatype)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mat_test mat_demo.cpp)
target_link_libraries(mat_test ${OpenCV_LIBS})

add_executable(cv_basic_datatype cv_basic_datatype.cpp)
target_link_libraries(cv_basic_datatype ${OpenCV_LIBRARIES})
