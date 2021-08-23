#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

struct userdata{
    Mat im;
    vector<Point2f> points;
};

int main( int argc, char** argv)
{
    Mat im_src = imread("../test.png");

	imshow("source image", im_src);
    // waitKey(0);

    //create a mask
    Mat mask(im_src.rows,im_src.cols,CV_8UC3,Scalar(0,0,0));
    circle(mask,Point(mask.cols/2,mask.rows/2),300,CV_RGB(255,255,255),-1);
    imshow("mask", mask);
    // waitKey(0);

    //apply mask to source image
    Mat im_res;
    bitwise_and(im_src, mask, im_res);
    imshow("apply mask to source image", im_res);
    waitKey(0);

    return 0;
}
