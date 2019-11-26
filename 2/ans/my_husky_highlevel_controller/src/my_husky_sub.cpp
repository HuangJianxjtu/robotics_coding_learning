#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void scan_callback(const sensor_msgs::LaserScan& laser_scan)
{
    // ROS_INFO_STREAM("hello world!");
    float min_range = 1000;
    for(int i=0;i<laser_scan.ranges.size();i++)
    {
        if(laser_scan.ranges[i] < min_range)
            min_range=laser_scan.ranges[i];
    }
    ROS_INFO("the minimum range: %f",min_range);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_husky_sub");  //"my_husky_sub" is node name
    ros::NodeHandle nh_("~");   //private node handle; "~"表示命名空间为当前节点名字

    // get parameter from the server
    std::string topic;
    if (!nh_.getParam("topic",topic)) //Relative parameter name
    {
        ROS_ERROR("Could not find topic parameter!");
    }
    int queue_size;
    if (!nh_.getParam("queue_size",queue_size))
    {
        ROS_ERROR("Could not find queue_size parameter!");
    }

    ros::Subscriber sub = nh_.subscribe(topic, queue_size, scan_callback);

    ros::spin();
    return 0;
}