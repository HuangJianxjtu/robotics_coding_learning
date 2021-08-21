cmake_minimum_required(VERSION 3.0)
project(read_an_image_file)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(read_image read_img.cpp)
target_link_libraries(read_image ${OpenCV_LIBRARIES})
