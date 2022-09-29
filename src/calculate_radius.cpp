/**
 * @file calculate_radius.cpp
 * @author hang chen (thomaszb@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "calculate_radius.h"

#include "calculate_radius_cost_function.h"

using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solve;
using ceres::Solver;

double CalculateRadius::GetCalculateResult(
    std::vector<Eigen::Vector2d>& points_pose, std::array<double, 3>& initial_xyr) {
  Problem problem;
  std::array<double, 3> result = initial_xyr;

  /* 添加优化变量 */
  problem.AddParameterBlock(result.data(), 3);

  /* 添加残差块 */
  for (const Eigen::Vector2d &point_pose : points_pose) {
    problem.AddResidualBlock(CreateRadiusCalculateCostFunction(point_pose),
                             nullptr, result.data());
  }

  /* 优化得到结果 */
  Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  Solver::Summary summary;
  Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n";
  std::cout << "result: (" << result[0] << ", " << result[1] << ", "
            << result[2] << ")" << std::endl;
  return result[2];
}
