/**
 * @file calculate_radius_cost_function.h
 * @author hang chen (thomaszb@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __CALCULATE_RADIUS_COST_FUNC_H_
#define __CALCULATE_RADIUS_COST_FUNC_H_

#include "ceres/ceres.h"

ceres::CostFunction* CreateRadiusCalculateCostFunction(
    const Eigen::Vector2d& point_pose);

#endif
