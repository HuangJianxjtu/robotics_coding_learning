#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    // image_transport::Publisher pub = it.advertise("camera/image", 1);
    image_transport::Publisher pub = it.advertise("/usb_cam/image_raw", 1);

    // NOTE: pay attention to the path of image file.
    // For CLion, set the working directory when debugging
    // cv::Mat image = cv::imread("./image0.png");
    cv::Mat image = cv::imread("/home/jian/Documents/codes/vlc_detection/data/image2.png");
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

    ros::Rate loop_rate(5);
    while (nh.ok()) {
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
