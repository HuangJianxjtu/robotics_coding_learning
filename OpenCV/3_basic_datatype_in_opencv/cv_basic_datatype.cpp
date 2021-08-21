https://blog.csdn.net/qq_29540745/article/details/52517269
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat m(3, 3, CV_8UC3);  //CV_8UC3是OpenCV的数据类型，3通道，8位无符号(0~255)
    m.at<Vec3b>(0, 0) = 257;
    cout<<m.at<Vec3b>(0, 0)<<endl;

    uchar aa = 1;  // unchar的取值范围是0~255; char的取值范围是-128~127
    cout<<aa<<endl;

    Vec3b p;   //一个uchar类型的vector, 长度为3
    for(auto i=0;i<=3;i++){
        for(auto j=0;j<3;j++){
            p[0]=i;
            p[1]=j;
            p[2]=i+j;
            m.at<Vec3b>(i, j)=p;
        }
    }
    cout<<"数组："<<endl<<"M="<<endl<<m<<endl;
    int a = m.at<Vec3b>(2, 2)[2];
    Vec3b b = m.at<Vec3b>(2,2);
    cout << "访问一个数：" << a <<endl<<"访问三通道："<<b<<endl;

    return 0;
}
