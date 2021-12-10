# NOTE: should NOT creat project in the subdirectory
message(STATUS "subdir: This is PROJECT_BINARY_DIR" ${PROJECT_BINARY_DIR})
# NOTE: note the difference between PROJECT_SOURCE_DIR and CMAKE_CURRENT_SOURCE_DIR
message(STATUS "subdir: This is PROJECT_SOURCE_DIR" ${PROJECT_SOURCE_DIR})
message(STATUS "subdir: This is CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(hello main.cpp)
