//
// Created by jian on 23/3/2020.
//

#include "../include/myClass.h"

my_class::my_class(ros::NodeHandle* nodeHandle):nh_(*nodeHandle)
{
    sub = nh_.subscribe("/chatter", 10, &my_class::callback, this);
    pub = nh_.advertise<std_msgs::String>("/chatter", 10, true);
}

void my_class::callback(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}
