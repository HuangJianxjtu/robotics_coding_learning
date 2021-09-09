#include <iostream>
#include <ceres/ceres.h>

using namespace std;
using namespace ceres;

/**
 * @reference https://blog.csdn.net/SUQIGUANG1/article/details/104239212
 * 求解使得0.5F(X)^2最小的X, F(X)=[f1(X), f2(X), f3(X), f4(X)]
 * ParameterBlock: X=[x1, x2, x3, x4]
 * f1(X)=x1+10*x2
 * f2(X)=sqrt(5)*(x3-x4)
 * f3(X)=(x2-2x3)^2
 * f4(X)=sqrt(10)*(x1-x4)^2
 */
// 1. construct the cost functor
struct F1 {
    template <typename T>
    bool operator()(const T* const x1, const T* const x2, T* residual) const {
        residual[0] = x1[0]+T(10)*x2[0];
        return true;
    }
};
struct F2 {
    template <typename T>
    bool operator()(const T* const x3, const T* const x4, T* residual) const {
        residual[0] = T(sqrt(5))*(x3[0]-x4[0]);
        return true;
    }
};
struct F3 {
    template <typename T>
    bool operator()(const T* const x2, const T* const x3, T* residual) const {
        residual[0] = (x2[0]-T(2)*x3[0])*(x2[0]-T(2)*x3[0]);
        return true;
    }
};
struct F4 {
    template <typename T>
    bool operator()(const T* const x1, const T* const x4, T* residual) const {
        residual[0] = T(sqrt(10))*(x1[0]-x4[0])*(x1[0]-x4[0]);
        return true;
    }
};

int main(){
    double x1 = 1.0, x2 = 2.0, x3 = 3.0, x4 = 4.0;

    //2. construct the optimization problem
    Problem problem;
    // 构造cost function

    problem.AddResidualBlock(new AutoDiffCostFunction<F1, 1, 1, 1>(new F1), nullptr, &x1, &x2);
    problem.AddResidualBlock(new AutoDiffCostFunction<F2, 1, 1, 1>(new F2), nullptr, &x3, &x4);
    problem.AddResidualBlock(new AutoDiffCostFunction<F3, 1, 1, 1>(new F3), nullptr, &x2, &x3);
    problem.AddResidualBlock(new AutoDiffCostFunction<F4, 1, 1, 1>(new F4), nullptr, &x1, &x4);
    //3. configure the solvers
    Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR; //配置增量方程的解法
    options.minimizer_progress_to_stdout = true;//输出到cout
    Solver::Summary summary;//优化信息
    Solve(options, &problem, &summary);//求解!!!

    cout<<summary.BriefReport()<<endl;
    cout << "result: "<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" "<< endl;

    return 0;
}