#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace cv;
using namespace std;
using namespace Eigen;

struct userdata{
    Mat im;
    vector<Point2f> points;
};

int main( int argc, char** argv)
{
    Mat im_src = imread("../test.png");

    Mat intrinsic_mat_K = (cv::Mat_<double>(3, 3) <<
            456.78, 0.0,     331.80,
            0.0,    456.64,  236.72,
            0.0,    0.00074, 1.0);
    Mat Kin = intrinsic_mat_K.inv();
    // cout<<intrinsic_mat_K*Kin<< endl;

    //3.0 初始化欧拉角(Z-Y-X，rad, 即第一个值是z轴旋转的值。即RPY, 先绕x轴roll,再绕y轴pitch,最后绕z轴yaw).
    Eigen::Vector3d ea_angle(0.5*0.785398, 0.0, 0.0);
    Eigen::Matrix3d rotation_matrix3;
    rotation_matrix3 = Eigen::AngleAxisd(ea_angle[0], Eigen::Vector3d::UnitZ()) *
            Eigen::AngleAxisd(ea_angle[1], Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(ea_angle[2], Eigen::Vector3d::UnitX());
    cout << "rotation matrix3 =\n" << rotation_matrix3(0,0) << endl;

    Mat mat_R = Mat::zeros(3, 3, CV_64F);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mat_R.at<double>(i, j) = rotation_matrix3(i,j);
        }
    }
    cout<<mat_R<<endl;

    Mat homoMatrix;
    homoMatrix = intrinsic_mat_K*mat_R*Kin;
    cout<<homoMatrix<<endl;

    Mat im_out;
    warpPerspective(im_src, im_out, homoMatrix, im_src.size());

    // Display image.
	imshow("Source Image", im_src);
	// imshow("Destination Image", im_dst);
	imshow("Warped Source Image", im_out);
    waitKey(0);

    return 0;
}
