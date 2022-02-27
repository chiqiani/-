#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
    cv::VideoCapture capture(0);
    if(!capture.isOpened()){
        std::cout<<"failture";
        return -1;
    }
    while(1){
        cv::Mat src,dst1,dst2,dst3;
        capture>>src;
        cv::blur(src,dst1,cv::Size(8,8));//均值滤波
        cv::medianBlur(src,dst2,5);//中值滤波
        cv::GaussianBlur(src,dst3,cv::Size(5,5),0,0);//高斯滤波
        cv::imshow("dst1",dst1);
        cv::imshow("dst2",dst2);
        cv::imshow("dst3",dst3);
        if(cv::waitKey(30)==27){
            break;
        }

    }
    return 0;
    
}