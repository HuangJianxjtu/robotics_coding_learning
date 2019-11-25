#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

void scan_callback(const sensor_msgs::LaserScan& laser_scan)
{
    float min_range = 0;
    for(int i=0;i<laser_scan.ranges.size();i++)
    {
        if(laser_scan.ranges[i]<min_range)
            min_range=laser_scan.ranges[i];
    }
    ROS_INFO_STREAM(min_range);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_husky_sub");  //"my_husky_sub" is node name
    ros::NodeHandle nh_;

    // get parameter from the server
    std::string topic;
    if (!nh_.getParam("topic",topic)) 
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