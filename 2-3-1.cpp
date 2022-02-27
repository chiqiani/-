#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
	cv::Mat src=cv::imread("/home/dqs/桌面/实验/3.jpeg");
    cv::Mat frame,mask,dst1,dst2,dst3,dst4;
    cv::cvtColor(src, frame,cv::COLOR_BGR2GRAY);//转化为灰度图
    cv::threshold(frame,mask,0,255,cv::THRESH_BINARY | cv::THRESH_OTSU);//二值化
    cv::Mat element=cv::getStructuringElement(cv::MORPH_RECT,cv::Size(10,10),cv::Point(-1,-1));//获取自定义核
    //cv::dilate(mask,dst1,element);膨胀
    //cv::erode(mask,dst2,element);核
    cv::morphologyEx(mask,dst1,cv::MORPH_DILATE,element);//膨胀
    cv::morphologyEx(mask,dst2,cv::MORPH_ERODE,element);//腐蚀
    cv::morphologyEx(mask,dst3,cv::MORPH_OPEN,element);//开运算
    cv::morphologyEx(mask,dst4,cv::MORPH_CLOSE,element);//闭运算
    cv::imshow("mask",mask);
    cv::imshow("膨胀",dst1);
    cv::imshow("腐蚀",dst2);
    cv::imshow("开运算",dst3);
    cv::imshow("闭运算",dst4);
    cv::imwrite("2-3-1-原图.jpeg",mask);
    cv::imwrite("2-3-1-膨胀.jpeg",dst1);
    cv::imwrite("2-3-1-腐蚀.jpeg",dst2);
    cv::imwrite("2-3-1-开运算.jpeg",dst3);
    cv::imwrite("2-3-1-闭运算.jpeg",dst4);
    cv::waitKey(0);
    return 0;
    
    
}