#pragma once

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/LaserScan.h>

namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	HuskyHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyHighlevelController();

private:
	ros::NodeHandle nodeHandle_;
	std::string topic;
	int queue_size;
	ros::Subscriber sub;
	void laser_callback(const sensor_msgs::LaserScan& laser_scan);
};

} /* namespace */
