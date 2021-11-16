#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "msgs_demo/demo_msgs.h" //引入自定义消息类型，虽然是demo_msgs.msg,这里却是.h

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_talker");
    ros::NodeHandle n;

    // 使用自定义消息类型
    ros::Publisher chatter_pub = n.advertise<msgs_demo::demo_msgs>("chatter", 1000);

    ros::Rate loop_rate(10); //10hz
    int count = 0;
    while (ros::ok())
    {
        // 使用自定义消息类型
        msgs_demo::demo_msgs speed;

        float i;
        i++;
        speed.front_left_speed = i;
        speed.front_right_speed = i + 1;
        speed.back_left_speed = i + 2;
        speed.back_right_speed = i + 3;
        chatter_pub.publish(speed); //发布消息

        // 循环等待回调函数
        ros::spinOnce(); //查询一次回调函数是否有消息进来

        loop_rate.sleep();
        ++count;
    }

    return 0;
}