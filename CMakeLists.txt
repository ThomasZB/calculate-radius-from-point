project(calculate_radius)

# 设置bin文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  

# 设置源文件和头文件
set(SRC_LIST src/main.cpp 
             src/calculate_radius.cpp 
             src/calculate_radius_cost_function.cpp) 
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS}
                    ${PROJECT_SOURCE_DIR}/inc
                    /usr/include/eigen3)

# 编译成可执行文件
add_executable(calculate_radius ${SRC_LIST})

# 链接
target_link_libraries(calculate_radius ${CERES_LIBRARIES})

