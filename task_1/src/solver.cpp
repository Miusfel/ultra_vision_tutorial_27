#include "../include/solver.hpp"
#include <cmath>

namespace task
{   
    bool Solver::solve(const std::vector<cv::Point3f> & obj_points, const std::vector<cv::Point2f> & armor_points)
    {
        //  这个函数需要调用cv::solvePnP来解出平移向量和旋转向量
        cv::solvePnP(obj_points, armor_points, camera_matrix, distort_coeffs, r_vec, t_vec);//这两个未初始化的mat会由solvePnP调用tvec.create(3, 1, CV_64F)来自动初始化
        double x, y, z;
        x = t_vec.at<double>(0, 0);//获取x,y,z的平移量
        y = t_vec.at<double>(1, 0);
        z = t_vec.at<double>(2, 0);
        six_dofs.position = cv::Vec3d(x, y, z);//将平移向量存入six_dofs.position
        //似乎缺少对旋转向量的处理逻辑




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
        //这里缺少从旋转向量到旋转矩阵的转换逻辑



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

        //这里缺少方位角的来源与处理


        six_dofs.euler = cv::Vec3d(yaw * RAD2DEG, pitch * RAD2DEG, roll * RAD2DEG);//将弧度转换为角度存入six_dofs.euler
        return 1;    
    }

    bool Solver::vec2euler()//这个函数需要将向量转换为欧拉角,未编写逻辑
    {
    }
}