#include <iostream>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

/**
 * 本程序演示了Eigen基本类型的使用,主要包括Matrix, Vector
 */

int main(){
    Matrix<double, 3, 3> mat_1; //矩阵
    Vector3d v1;  //向量. 实质上是 Eigen::Matrix<double, 3, 1>，即三维向量

    //赋值
    mat_1(1, 1) = 1.0;//单个赋值
    v1(1) = 1.0;
    mat_1<<1,2,3,4,5,6,7,8,9;//批量赋值
    v1<<6,4,3;
    cout<<mat_1(1,1)<<endl;
    cout<<mat_1<<endl;
    cout<<v1<<endl;
    Matrix3d mat_33 = Matrix3d::Zero();//初始化为0
    cout<<mat_33<<endl;

    //矩阵相乘（或者矩阵向量相乘）
    Vector3d res;
    res = mat_1 * v1;
    cout<<res<<endl;
}

