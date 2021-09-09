#include <iostream>
#include <ceres/ceres.h>

using namespace std;
using namespace ceres;

/**
 * @reference https://blog.csdn.net/SUQIGUANG1/article/details/104239212
 * 求解使得0.5(10-x)^2最小的x
 * ResidualBlock: (10-x)^2
 * CostFunction： 10-x
 * lossFunction: 0.5, 因为是常数所以设为nullptr
 * ParameterBlock: x
 */
// 1. construct the cost function. 构建代价函数，重载（）符号，仿函数的小技巧
struct CostFunctor {
    template <typename T>  // define a template named T
    bool operator()(const T* const x, T* residual) const {
        residual[0] = T(10.0) - x[0];
        return true;
    }
};

int main(){
    double x_init = 100.0;

    //2. construct the optimization problem
    Problem problem;
    // 构造cost function.使用自动求导：将之前的代价函数结构体传入，第一个1是输出维度，即残差的维度，第二个1是输入维度，即待寻优参数x的维度
    CostFunction* my_cost_function = new AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);

    problem.AddResidualBlock(my_cost_function , nullptr, &x_init);
    //3. configure the solvers
    Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR; //配置增量方程的解法
    options.minimizer_progress_to_stdout = true;//输出到cout
    Solver::Summary summary;//优化信息
    Solve(options, &problem, &summary);//求解!!!

    cout<<summary.BriefReport()<<endl;
    cout << "result: "<<x_init<< endl;

    return 0;
}