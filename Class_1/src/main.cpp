#include <iostream>
#include <opencv2/opencv.hpp>

#include "../include/detector.hpp"

int main()
{
    //Step1 完成图片的读取和显示  图片路径为image/vision.jpg
    cv::Mat img;
    img = cv::imread("vision/picture.jpg");
    //======================

    //Step2 定义并初始化一个detector类
    task::Detector detector;
    
    //Step3 定义一个armor类型的vector容器
    std::vector<task::Armor> armors;

    //Step4 调用前面定义的detector的detect()函数得到识别结果
    armors = detector.detect(img);

    //Step5 在读取的图片中画出识别出的armor
    if(!armors.empty())
    {
        auto armor = armors.front();
        std::vector<cv::Point> int_points(armor.points.begin(), armor.points.end());
        for(int j = 0 ; j < 4; j++){
            cv::circle(img, int_points[j], 5, cv::Scalar(0, 255, 255), -1);
            cv::line(img, int_points[j], int_points[(j+1) % 4], cv::Scalar(0 ,255, 0), 2);
        }
    }

    //Step6 显示结果
    cv::resize(img, img, cv::Size(0, 0), 0.5, 0.5);
    cv::imshow("Result", img);

    cv::waitKey(0);
    return 0;
}