//
// Created by jian on 23/3/2020.
//

#ifndef ROS_CLASS_CPP_DEMO_MYCLASS_H
#define ROS_CLASS_CPP_DEMO_MYCLASS_H

// include headers
#include <ros/ros.h>
#include <std_msgs/String.h>

class my_class {
public:
    //"main" will need to instantiate a ROS nodeHandle, then pass it to the constructor
    my_class(ros::NodeHandle* nodeHandle);      // constructor
    ros::Publisher pub;
private:
    // we will need this, to pass between "main" and constructor
    ros::NodeHandle nh_;
    ros::Subscriber sub;
    void callback(const std_msgs::String::ConstPtr& msg);
};


#endif //ROS_CLASS_CPP_DEMO_MYCLASS_H
