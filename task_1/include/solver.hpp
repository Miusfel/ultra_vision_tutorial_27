#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <opencv2/opencv.hpp>

namespace task
{

//  相机内参
static const cv::Mat camera_matrix =
    (cv::Mat_<double>(3, 3) <<  1286.307063384126 , 0                  , 645.34450819155256, 
                                0                 , 1288.1400736562441 , 483.6163720308021 , 
                                0                 , 0                  , 1                   );
// 畸变系数
static const cv::Mat distort_coeffs =
    (cv::Mat_<double>(1, 5) << -0.47562935060124745, 0.21831745829617311, 0.0004957613589406044, -0.00034617769548693592, 0);

static const double LIGHTBAR_LENGTH = 0.056; //灯条物理长度 单位：米
static const double ARMOR_WIDTH = 0.135; // 装甲板宽带 单位：米

// object_points 是 物体局部坐标系下 n个点 的坐标。
// 对于我们而言，也就是装甲板坐标系下4个点的坐标。
// 请你填写下面的 object_points:
static const std::vector<cv::Point3f> object_points {
    {0, 0, 0},         //Point 1   left_top
    {0, 0, 0},         //Point 2   right_top
    {0, 0, 0},         //Point 3   right_bottom
    {0, 0, 0}          //Point 4   left_bottom
 };

const double RAD2DEG = 180.0 / CV_PI;

 struct SixDofs
 {  
    cv::Vec3d position; //x, y, z
    cv::Vec3d euler;    // yaw, pitch, roll
 };
 

class Solver
{
private:
    cv::Mat t_vec;   //平移vector
    cv::Mat r_vec;   //旋转vector
    cv::Mat r_mat;  //旋转Mat
    SixDofs six_dofs; //6自由度信息
public:
    cv::Mat getTvec(){return t_vec;}
    cv::Mat getRvec(){return r_vec;}
    cv::Mat getRmat(){return r_mat;}

    bool solve( const std::vector<cv::Point3f> & obj_points,
                const std::vector<cv::Point2f> & armor_points);
    bool vec2mat(const cv::Mat & rvec);
    bool mat2euler(const cv::Mat & rmat);
    bool vec2euler();

    SixDofs get6dof(){return six_dofs;}
};


} // namespace Solver


#endif