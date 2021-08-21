// https://blog.csdn.net/Gordon_Wei/article/details/85037684
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    /**
     * 1. Mat用于图像的读取、操作和赋值
     */
     Mat im_src = imread("../test.png"); //读取
     imshow("source image", im_src);  //显示
     cv::waitKey(0);
     Mat im_dst = im_src.clone();
     for(int i = 0; i<im_src.rows; i++){    //赋值
         for(int j=0; j<im_src.cols; j++){
             im_dst.at<Vec3b>(i, j)[0] = 0.5; // B channel
             im_dst.at<Vec3b>(i, j)[1] = 0.5; // G channel
             im_dst.at<Vec3b>(i, j)[2] = 255; // R channel
         }
     }
     imshow("destination image", im_dst);
     waitKey(0);

     /**
      * 2. Mat用于矩阵
      */
      Mat rotationMatrix = (Mat_<double>(3, 3) <<
              1.0, 2.0, 3.0,
              0.0, 1.0, 0.0,
              0.0, 0.0, 1.0);

      Mat A = Mat::zeros(3, 3, CV_64F);
      Mat B = Mat::ones(3,3, CV_64F);
      Mat C = Mat::eye(3, 3, CV_64F);

      cout<<"A :"<<endl<<A<<endl;
      cout<<"B :"<<endl<<B<<endl;
      A = B+C;
      A = B-C;
      A = B*C;
      A = 5*B;
      A = rotationMatrix.t();
      cout<<A<<endl;
      A = rotationMatrix.inv();
      cout<<A<<endl;
      cout<<A*rotationMatrix<<endl;


      return 0;
}