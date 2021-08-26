# CMake系列学习（2）-- 如何使用库

## 本项目展示了如何生成并调用一个C++库

## 总结

>* (1)程序代码由头文件和源文件组成；
>* (2)带有main函数的源文件编译成可执行程序，其他的编译成库文件
>* (3)如果可执行程序想调用库文件中的函数，它需要参考该库文件提供的头文件，以明白调用的格式。同时，要把可执行程序链接到库文件上。

参考:《视觉SLAM十四讲》的第2讲