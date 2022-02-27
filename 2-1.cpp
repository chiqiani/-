#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
    cv::Mat src=cv::imread("/home/dqs/桌面/实验/1.jpeg");
    cv::Mat frame,mask;
    cv::cvtColor(src,frame,cv::COLOR_BGR2HSV);//将bgr转化为hsv
    cv::Scalar s1(100,43,46);
    cv::Scalar s2(124,255,255);
    cv::inRange(frame,s1,s2,mask);//二值化
    cv::imshow("mask",mask);
    cv::imwrite("2-1-原图.jpeg",src);
    cv::imwrite("2-1-hsv.jpeg",mask);
    cv::waitKey();
}
