#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    Mat src=imread("/home/dqs/桌面/实验/1.jpeg");
   
     Mat p[3];//vector<Mat> p; Vec3b p;
     split(src,p);//
     imshow("B",p[0]);
     imshow("G",p[1]);
     imshow("R",p[2]);
     imwrite("1-4-B.jpeg",p[0]);
     imwrite("1-4-G.jpeg",p[1]);
     imwrite("1-4-R.jpeg",p[2]);
    waitKey(0);
    return 0;
}
