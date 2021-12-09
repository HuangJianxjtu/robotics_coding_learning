#include "husky_highlevel_controller/HuskyHighlevelController.hpp"

namespace husky_highlevel_controller {

HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	if (!nodeHandle_.getParam("topic",topic)) //Relative parameter name
    {
        ROS_ERROR("Could not find topic parameter!");
    }
	if (!nodeHandle_.getParam("queue_size",queue_size))
    {
        ROS_ERROR("Could not find queue_size parameter!");
    }
	sub = nodeHandle_.subscribe(topic, queue_size, &HuskyHighlevelController::laser_callback,this);
}

HuskyHighlevelController::~HuskyHighlevelController()
{
};

void HuskyHighlevelController::laser_callback(const sensor_msgs::LaserScan& laser_scan)
{
    float min_range = 1000;
    for(int i=0;i<laser_scan.ranges.size();i++)
    {
        if(laser_scan.ranges[i] < min_range)
            min_range=laser_scan.ranges[i];
    }
    ROS_INFO("the minimum range: %f",min_range);
}
} /* namespace */
