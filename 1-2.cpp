#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    Mat src=imread("/home/dqs/桌面/实验/1.jpeg");
    Vec3b p;
    uchar a=100;

    int rows=src.rows;//获得行列
    int cols=src.cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            p[0]=(src.at<Vec3b>(i,j)[0]+src.at<Vec3b>(i,j)[1]+src.at<Vec3b>(i,j)[2])/3;//获得均值
            if(p[0]>a){//与100作比较
                p[0]=255;
            }
            else{
                p[0]=0;
            }
            src.at<Vec3b>(i,j)[0]=p[0];
            src.at<Vec3b>(i,j)[1]=p[0];
            src.at<Vec3b>(i,j)[2]=p[0];
        }
    }
    imshow("1",src);
    imwrite("1-2.jpeg",src);
    waitKey(0);
    return 0;
}
