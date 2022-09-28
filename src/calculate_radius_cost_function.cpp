/**
 * @file calculate_radius_cost_function.cpp
 * @author hang chen (thomaszb@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "calculate_radius_cost_function.h"

/**
 * @brief 残差函数
 *
 */
struct CostFunctor {
 public:
  explicit CostFunctor(Eigen::Vector2d point_pose) : point_pose_(point_pose) {}

  template <typename T>
  bool operator()(const T* const x, T* residual) const {
    /* x中为圆心(x,y)，半径r */
    T delta_x = x[0] - point_pose_[0];
    T delta_y = x[1] - point_pose_[1];
    residual[0] = sqrt(delta_x * delta_x + delta_y * delta_y) - x[2];
    return true;
  }

 private:
  const Eigen::Vector2d point_pose_;
};

/**
 * @brief Create a Radius Calculate Cost Function object
 *
 * @param point_pose :轨迹点
 * @return ceres::CostFunction*
 */
ceres::CostFunction* CreateRadiusCalculateCostFunction(
    const Eigen::Vector2d& point_pose) {
  return new ceres::AutoDiffCostFunction<CostFunctor, 1 /* residuals */,
                                         3 /* pose and radius */>(
      new CostFunctor(point_pose));
}
