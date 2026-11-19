#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include <vector>
#include <opencv2/opencv.hpp>

#include "armor.hpp"

namespace task
{
class Detector
{
public:
  std::vector<Armor> detect(const cv::Mat & bgr_img);//接受一个Mat图片对象bgr_img,
                                                     //识别其中的装甲数据,返回一个vector<Armor>对象

private:
  bool check_geometry(const Lightbar & lightbar);
  bool check_geometry(const Armor & armor);

  Color get_color(const cv::Mat & bgr_img, const std::vector<cv::Point> & contour);
  cv::Mat get_pattern(const cv::Mat & bgr_img, const Armor & armor);
  
};

}  // namespace auto_aim

#endif