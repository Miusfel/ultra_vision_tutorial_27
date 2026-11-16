#include "../include/solver.hpp"
#include <cmath>

namespace task
{   
    bool Solver::solve(const std::vector<cv::Point3f> & obj_points, const std::vector<cv::Point2f> & armor_points)
    {
        //  这个函数需要调用cv::solvePnP来解出平移向量和旋转向量
        cv::solvePnP(obj_points, armor_points, camera_matrix, distort_coeffs, r_vec, t_vec);
        double x, y, z;
        x = t_vec.at<double>(0, 0);
        y = t_vec.at<double>(1, 0);
        z = t_vec.at<double>(2, 0);
        six_dofs.position = cv::Vec3d(x, y, z);
        return 1;
    }

    bool Solver::vec2mat(const cv::Mat & rvec)
    {   
        //  这个函数需要调用cv::Rodrigues来完成旋转向量到旋转矩阵的转换
        if(rvec.empty())
        {   
            std::cerr << "[Solver] R'Vector error!" << std::endl; 
            return 0;
        }

        return 1;
    }

    bool Solver::mat2euler(const cv::Mat & Rmat)
    {   
        //  这个函数需要选择旋转矩阵某些元素并利用反三角函数计算出三个欧拉角
        if(Rmat.empty())
        {
            std::cerr << "[Solver] R'Mat error" << std::endl;
            return 0;
        }
        cv::Mat rmat;

        double roll, pitch, yaw;
        yaw = 0;
        pitch = 0;
        roll = 0;
        six_dofs.euler = cv::Vec3d(yaw * RAD2DEG, pitch * RAD2DEG, roll * RAD2DEG);
        return 1;    
    }

    bool Solver::vec2euler()
    {
    }
}