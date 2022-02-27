#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    Mat src=imread("/home/dqs/桌面/实验/1.jpeg");
    Mat src1=src.clone();//深复制得到两个Mat;
    Mat src2=src.clone();
    Point p1(10,10);//得到两个点
    Point p2(100,100);
    line(src,p1,p2,Scalar(0,0,255),5);//画线
    rectangle(src1,p1,p2,Scalar(0,255,0),2);//画矩形
    circle(src2,p2,15,Scalar(255,0,0),2);//画圆
    imshow("line",src);
    imshow("rectangle",src1);
    imshow("circle",src2);
    imwrite("1-6-line.jpeg",src);
    imwrite("1-6-rectangle.jpeg",src1);
    imwrite("1-6-circle.jpeg",src2);
    waitKey(0);
    return 0;
}
