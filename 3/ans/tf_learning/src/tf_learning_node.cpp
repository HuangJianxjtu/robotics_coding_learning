#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>

int main(int argc, char** argv) 
{
    ros::init(argc, argv, "tf2_listener");
    ros::NodeHandle nodeHandle;
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate rate(10.0);
    while (nodeHandle.ok())
    {
        geometry_msgs::TransformStamped transformStamped;
        try 
        {
            //wait until a transform becomes available.ros::Duration(3.0)是过期时间
            transformStamped = tfBuffer.lookupTransform("odom","base_link", ros::Time(0),ros::Duration(3.0));
        }
        catch (tf2::TransformException &exception) 
        {
            ROS_WARN("%s", exception.what());
            ros::Duration(1.0).sleep();
            continue;
        }
        ROS_INFO_STREAM(transformStamped.transform.translation.x<<","<<transformStamped.transform.translation.y<<","<<transformStamped.transform.translation.z);
        rate.sleep();
    }
    return 0;
}