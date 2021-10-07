cmake_minimum_required(VERSION 3.0.2)
project(6_detect_optical_flow)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(OpenCV)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})
