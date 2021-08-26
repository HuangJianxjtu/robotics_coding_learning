cmake_minimum_required(VERSION 3.0.2)
project(mask_demo)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(OpenCV)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(main mask_demo.cpp)
target_link_libraries(main ${OpenCV_LIBS})

add_executable(create_mask creat_mask.cpp)
target_link_libraries(create_mask ${OpenCV_LIBS})
