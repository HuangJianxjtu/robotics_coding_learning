# 关于ROS course1的笔记

## 1 ROS中可以使用键盘和手柄两种方式来遥控机器人

### 1.1 用源码安装teloep_twist_keyboard（键盘）

>* 在catkin_ws的src中下载源码：`git clone https://github.com/ros-teleop/teleop_twist_keyboard.git`
>* 回到catkin_ws，执行`catkin_make`
>* 执行`source devel/setup.bash`; 之后就可以使用teloep_twist_keyboard了（或者为了方便，将`source ~/catkin_ws/devel/setup.bash`写入~/.bashrc中）
>* teloep_twist_keyboard的使用：`rosrun teleop_twist_keyboard teleop_twist_keyboard.py`
>* 此外可以使用apt-get install直接安装teloep_twist_keyboard，命令：`sudo apt-get install ros-kinetic-teleop-twist-keyboard`
>* <font color=#ffff00>**注意：**</font> teloep_twist_keyboard默认发布的topic是/cmd_vel,可以改变其topic的名称，比如改成/turtle1/cmd_vel(这样就可以控制turtlesim了)，命令：`rosrun teleop_twist_keyboard teleop_twist_keyboard.py /cmd_vel:=/turtle1/cmd_vel`. 下面的teleop_twist_joy也是一样。
>* <font color=#ffff00>**命令行安装（更方便）：**</font>`sudo apt-get install ros-<distri>-teleop-twist-keyboard`

### 1.2 teleop_twist_joy（手柄，更方便！）

>* 硬件：logitech F710手柄。这是标准手柄，即插即用，Ubuntu 16.04和Kinect中自带了joy驱动
>* 检查手柄的连接, `ls /dev/input/`;查看是否有js0,有则说明已经连接上了
>* 测试手柄信号，`sudo jstest /dev/input/js0`
>* 运行joy_node节点，查看话题消息。`rosrun joy joy_node`; `rostopic echo /joy`
>* 运行teleop_twist_joy, 查看话题消息。`rosrun teleop_twist_joy teleop_node`; `rostopic echo /cmd_vel`
>* 使用teleop_twist_joy：要按下"X"键后才能向/cmd_vel发布命令，即此时方向控制键才会生效。需要不断重复按下方向键，才能使机器人持续移动（很麻烦！）

----------------------------------------------------------------------------

>* <font color=#ffff00>**注意:**</font> teleop_twist_joy本身并不好用，但是它提供了API供开发者开发，因此我们可以自定义更方便的遥控方式。请参考：

## 2 关于roslaunch

>* 当用roslaunch启动nodes时，如果此时roscore还没有运行，roslaunch会先自动运行roscore，再运行我们的nodes！非常棒！
>* 对于roslaunch的基本要求：（1）学会用roslaunch启动节点（包括C++节点和python文件节点）;（2）学会使用arg(参数设置)；(3)学会在launch文件中启动另一个lanuch文件(include语句).
