/**
 * @file calculate_radius.h
 * @author hang chen (thomaszb@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __CALCULATE_RADIUS_H_
#define __CALCULATE_RADIUS_H_

#include "ceres/ceres.h"
#include "glog/logging.h"

class CalculateRadius {
 public:
  CalculateRadius() {}
  double GetCalculateResult(std::vector<Eigen::Vector2d>& points_pose,
                            std::array<double, 3>& initial_xyr);
};

#endif