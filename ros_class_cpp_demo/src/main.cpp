//
// Created by jian on 22/3/2020.
//
#include "myClass.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_class_cpp_node");  //"ros_class_cpp_node" is node name
    ros::NodeHandle nodeHandle;

    my_class class_ins(&nodeHandle);
    ros::Rate loop_rate(1);

    int count = 0;
    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss<<"hello world "<<count;
        msg.data = ss.str();
        ROS_INFO_STREAM("I said: "<<ss.str());
        class_ins.pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}