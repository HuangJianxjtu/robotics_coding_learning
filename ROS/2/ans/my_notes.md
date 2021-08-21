# 关于ROS course2的笔记

## 1 ros::spin()和ros::spinOnce()

这俩兄弟学名叫ROS消息回调处理函数。它俩通常会出现在ROS的主循环中，程序需要不断调用ros::spin() 或 ros::spinOnce()，**两者区别在于前者调用后不会再返回，也就是你的主程序到这儿就不往下执行了，而后者在调用后还可以继续执行之后的程序**。详见：`https://www.cnblogs.com/liu-fa/p/5925381.html`

