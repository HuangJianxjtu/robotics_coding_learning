# How to Add A Custom ROS Message

## How to Use

>* `catkin build` && `source devel/setup.zsh`
>* `rosmsg show msgs_demo/demo_msgs`
>* [参考](https://blog.csdn.net/wwwlyj123321/article/details/83617538)。但这篇文章有点啰嗦，还是以本文为主
>* [how to use in C++ and python](http://wiki.ros.org/ROS/Tutorials/DefiningCustomMessages). NOTE: .H is automatically generated.


[reference](http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv#Creating_a_msg)

[how to write .msg file](https://github.com/HuangJianxjtu/ROS-Academy-for-Beginners/tree/master/msgs_demo/msg)

### 如何在Python中使用自定义消息

python导入自定义消息模块，遵循一定的规范，from 模块名.msg import 具体的消息. [参考](https://robot.czxy.com/docs/ros/msg/pycall1/)。 我自己写的案例[example](./scripts/useDemoMsg.py)