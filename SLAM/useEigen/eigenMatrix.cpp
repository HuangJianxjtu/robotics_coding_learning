#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

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
    mat_1<<1, 0, 1,
           0, 2, 0,
           0, 0, 3;//批量赋值
    v1<<6,4,3;
    // cout<<mat_1(1,1)<<endl;
    cout<<"mat_1: \n"<<mat_1<<endl;
    // cout<<v1<<endl;
    Matrix3d mat_33 = Matrix3d::Zero();//初始化为0
    // cout<<mat_33<<endl;

    //矩阵相乘（或者矩阵向量相乘）
    Vector3d res;
    res = mat_1 * v1;
    // cout<<res<<endl;

    //转置行列式、逆矩阵
    cout<<"mat_1的转置: \n"<< mat_1.transpose()<<endl;
    cout<<"mat_1的行列式: \n"<< mat_1.determinant()<<endl;
    cout<<"mat_1的逆矩阵: \n"<< mat_1.inverse()<<endl;

    //求解线性方程 Ax =B;Answer=[1;2;3;4]
    // https://blog.csdn.net/hzwwpgmwy/article/details/84955051
    Matrix4d A;
    A << 1, 2, 3, 4,
         1, 4, 3, 2,
         1, 3, 2, 4,
         4, 1, 1, 3;
    Vector4d B(30, 26, 29, 21);
    Vector4d ans;
    // 通常用矩阵分解来求，例如QR分解，速度会快很多
    ans = A.colPivHouseholderQr().solve(B);
    cout << ans << endl;

    // 对于正定矩阵，还可以用cholesky分解来解方程,速度最快;但本程序中的矩阵A不是正定矩阵
    // 判断正定矩阵：特征值全部为正
    // ans = A.ldlt().solve(B);
}

