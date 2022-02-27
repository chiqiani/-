#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
	cv::Mat src=cv::imread("/home/dqs/桌面/实验/1.jpeg");
    cv::Mat frame,mask;
    cv::cvtColor(src, frame,cv::COLOR_BGR2GRAY);//得到灰度图
    cv::threshold(frame,mask,128,255,3);//二值化
    cv::imshow("1",frame);
    cv::imshow("mask",mask);
    cv::imwrite("2-2.jpeg",mask);
    cv::waitKey(0);
    return 0;
    
    
}
