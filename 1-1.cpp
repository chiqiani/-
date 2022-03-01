#include<iostream>
#include<opencv2/opencv.hpp>
int main(){
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/5.jpeg");
    cv::Mat orc=src.clone();
    int p;
    int rows=src.rows;
    int cols=src.cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            p=(src.at<cv::Vec3b>(i,j)[0]+src.at<cv::Vec3b>(i,j)[1]+src.at<cv::Vec3b>(i,j)[2])/3;//获得均值
            src.at<cv::Vec3b>(i,j)[0]=p;
            src.at<cv::Vec3b>(i,j)[1]=p;
            src.at<cv::Vec3b>(i,j)[2]=p;
        }
    }
    cv::imshow("src",src);
    cv::imwrite("1.jpeg",src);
    cv::imwrite("1-原图.jpeg",orc);
    cv::waitKey();
    return 0;
}