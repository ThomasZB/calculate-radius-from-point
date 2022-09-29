# calculate-radius-from-point
最近有个项目需要根据圆上面的点计算圆的半径，我通过使用google的优化库ceres，优化得到圆的圆心和中心

# 简介

假设圆心为 $(x, y)$ ，可以得到：

$$ \Delta x=x_n-x $$

$$ \\Delta y=y_n-y $$

假设半径为 $r$ ，可以得到每个点的误差为：

$$ err_n=\left(\sqrt{\Delta x_n^2+\Delta y_n^2}-r\right)^2 $$

一共采集 $m$ 个点，可得总的误差为：

$$ err=\sum_{i=0}^{m-1}err_n $$

通过优化的方式，使得总的误差最小即可得到圆心和半径 $(x, y, r)$ 

# 使用

## 编译

创建`build`目录，进入后`cmake .. `创建`Makefile`，再使用`make`编译，就可以得到二进制文件（`bin`目录下）

> mkdir build
>
> cd build
>
> cmake ..
>
> make

代码的使用`main.cpp`给出了示例
