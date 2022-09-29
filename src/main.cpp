/**
 * @file main.cpp
 * @author hang chen (thomaszb@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-09-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "calculate_radius.h"

int main() {
  CalculateRadius my_test;
  std::vector<Eigen::Vector2d> my_test_points;
  std::array<double, 3> inital_xyr = {0, 0, 0};

  my_test_points.push_back(Eigen::Vector2d(2.1, 4.09));
  my_test_points.push_back(Eigen::Vector2d(3.95, 2.1));
  my_test_points.push_back(Eigen::Vector2d(1.91, 0.06));
  my_test_points.push_back(Eigen::Vector2d(-0.03, 2.06));

  my_test.GetCalculateResult(my_test_points, inital_xyr);
}
