#include "husky_highlevel_controller/HuskyHighlevelController.hpp"

namespace husky_highlevel_controller {

HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	if (!nodeHandle_.getParam("topic",topic)) //Relative parameter name
    {
        ROS_ERROR("Could not find parameter -- topic!");
    }
	if (!nodeHandle_.getParam("queue_size",queue_size))
    {
        ROS_ERROR("Could not find parameter --  queue_size!");
    }
    if (!nodeHandle_.getParam("k_v", k_v))
    {
        ROS_ERROR("Could not find parameter -- k_v!");
    }
    if (!nodeHandle_.getParam("k_angle", k_angle))
    {
        ROS_ERROR("Could not find parameter -- k_angle!");
    }
	sub = nodeHandle_.subscribe(topic, queue_size, &HuskyHighlevelController::laser_callback,this);
    pub = nodeHandle_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    vis_pub = nodeHandle_.advertise<visualization_msgs::Marker>("visualization_maker",1);

    // tf initialization -- 初始化共享指针对象(Question:为啥要用共享指针呢？)
    tfBuffer.reset(new tf2_ros::Buffer());
    tfListener.reset(new tf2_ros::TransformListener(*tfBuffer));
}

HuskyHighlevelController::~HuskyHighlevelController()
{
};

void HuskyHighlevelController::laser_callback(const sensor_msgs::LaserScan& laser_scan)
{
    float min_range = 1000;
    int index_ = 0;
    float x_pillar2laser, y_pillar2laser, theta_;
    for(int i=0;i<laser_scan.ranges.size();i++)
    {
        if(laser_scan.ranges[i] < min_range)
        {
            min_range=laser_scan.ranges[i];
            index_ = i;
        }
    }
    // ROS_INFO("the minimum range: %f",min_range);
    theta_ = laser_scan.angle_min + index_*laser_scan.angle_increment;
    x_pillar2laser = min_range*cos(theta_);
    y_pillar2laser = min_range*sin(theta_);

    geometry_msgs::PoseStamped poseStamped_laser, poseStamped_odom;  //定义一个位姿变量用来存储坐标值
    poseStamped_laser.header.frame_id = "base_laser";
    poseStamped_laser.header.stamp = ros::Time();
    tf2::toMsg(tf2::Transform::getIdentity(), poseStamped_laser.pose);
    poseStamped_laser.pose.position.x = x_pillar2laser;
    poseStamped_laser.pose.position.y = y_pillar2laser;

    try
    {
        // 把一个位姿从一个坐标系转换到另一个坐标系，这个与lookupTransform()不一样
        // wait until a transform becomes available.ros::Duration(1.0)是过期时间
        this->tfBuffer->transform(poseStamped_laser, poseStamped_odom, "odom", ros::Duration(1.0));//获取该点在odom中的坐标值
    }
    catch(tf2::TransformException e)
    {
        ROS_ERROR("%s", e.what());
    }

    // publish maker
    visualization_msgs::Marker vmarker;
    // vmarker.header.frame_id = "base_laser";    //  easy version

    vmarker.header.frame_id = "odom";    //  difficult version
    vmarker.header.stamp = ros::Time();
    vmarker.ns = "~";
    vmarker.id = 0;
    vmarker.type = visualization_msgs::Marker::SPHERE;
    vmarker.action = visualization_msgs::Marker::ADD;
    // vmarker.pose.position.x = x_pillar2laser;    //  easy version
    // vmarker.pose.position.y = y_pillar2laser;    //  easy version

    vmarker.pose.position.x = poseStamped_odom.pose.position.x;    //  difficult version
    vmarker.pose.position.y = poseStamped_odom.pose.position.y;    //  difficult version
    vmarker.pose.position.z = 0.0;
    vmarker.pose.orientation.x = 0.0;
    vmarker.pose.orientation.y = 0.0;
    vmarker.pose.orientation.z = 0.0;
    vmarker.pose.orientation.w = 1.0;
    vmarker.scale.x = 0.3;
    vmarker.scale.y = 0.3;
    vmarker.scale.z = 0.3;
    vmarker.color.a = 1.0;
    vmarker.color.r = 0.0;
    vmarker.color.g = 0.0;
    vmarker.color.b = 1.0;
    vis_pub.publish(vmarker);


    // P controller
    geometry_msgs::Twist vel_;
    vel_.linear.x = k_v*(min_range + 0.05);
    vel_.angular.z = k_angle*(0-theta_);
    pub.publish(vel_);
}
} /* namespace */
