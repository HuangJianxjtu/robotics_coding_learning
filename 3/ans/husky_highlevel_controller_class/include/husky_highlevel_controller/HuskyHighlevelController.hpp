#pragma once

#include <ros/ros.h>
#include <string>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/PoseStamped.h>

#include <tf2/convert.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/utils.h>

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
	ros::Publisher pub;
	ros::Publisher vis_pub;
	void laser_callback(const sensor_msgs::LaserScan& laser_scan);
	float k_v, k_angle;
	std::shared_ptr<tf2_ros::Buffer> tfBuffer;
	std::shared_ptr<tf2_ros::TransformListener> tfListener;
};

} /* namespace */
