#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/5.jpeg");
    cv::Mat dst1,dst2,dst2_x,dst2_y,abs_x,abs_y,dst3;
    cv::cvtColor(src,dst1,cv::COLOR_BGR2GRAY);//灰度化
    cv::GaussianBlur(dst1,dst2,cv::Size(5,5),0,0);//高斯滤波
    // cv::Sobel(dst2,dst2_x,CV_16S,1,0);
    // cv::Sobel(dst2,dst2_y,CV_16S,0,1);
    // cv::convertScaleAbs(dst2_x, abs_x);//使用线性变换转换输入数组元素成8位无符号整型
    // cv::convertScaleAbs(dst2_y, abs_y);//使用线性变换转换输入数组元素成8位无符号整型
    // cv::addWeighted(abs_x,0.5,abs_y,0.5,0,dst3);
    cv::Canny(dst2,dst3,20,80);
    cv::imshow("dst2",dst2);
    cv::imshow("dst3",dst3);
    cv::imwrite("2-3-5.jpeg",dst3);
    cv::waitKey();
    return 0;
    
}