cmake_minimum_required(VERSION 2.8)

# 下面的命令把文件编译成静态库(.a)。若想要编译成共享库(.so),则应该写成:add_library(hello SHARED src/libHello.cpp)
add_library(hello src/libHello.cpp)

# 添加可执行程序
add_executable(use_hello src/main.cpp)

# 把可执行程序链接到它所用到的库中，否则会出现"undefined reference"错误；调用其他标准库(如OpenCV,Eigen)也是如此
target_link_libraries(use_hello hello)
