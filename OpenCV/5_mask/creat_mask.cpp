#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
    Mat im_src = imread("../image_fisheye_480_realmask.png");

    imshow("source image", im_src);
    // waitKey(0);

    //create a mask
    Mat mask(im_src.rows,im_src.cols,CV_8UC1,Scalar(0,0,0));
    circle(mask,Point(mask.cols/2,mask.rows/2),300,CV_RGB(255,255,255),-1);

    for(int i=0;i<im_src.rows; i++){
        for(int j=0;j<im_src.cols; j++){
            if(im_src.at<Vec3b>(i,j)[2]>0 && mask.at<uchar>(i,j)>0){
                mask.at<uchar>(i,j) = 0;
            }
        }
    }

    // save and show the result
    imwrite("../image_fisheye_480_realmask_plus.jpg", mask);
    imshow("mask", mask);
    waitKey(0);

    return 0;
}
