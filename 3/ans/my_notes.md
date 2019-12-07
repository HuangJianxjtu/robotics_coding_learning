# 关于ROS course3的笔记

## 1. ros::spin()和ros::spinOnce()

这俩兄弟学名叫ROS消息回调处理函数。它俩通常会出现在ROS的主循环中，程序需要不断调用ros::spin() 或 ros::spinOnce()，**两者区别在于前者调用后不会再返回，也就是你的主程序到这儿就不往下执行了，而后者在调用后还可以继续执行之后的程序**。详见：`https://www.cnblogs.com/liu-fa/p/5925381.html`

## 2. tf2_ros::Buffer中的transform()和lookupTransform()

>* lookupTransform():查询一个frame另一个frame的transform
>* transform():把一个位姿从一个坐标系转换到另一个坐标系
>* 注意如何在class中使用他们,要用到共享指针（我还没有完全搞懂！！）
