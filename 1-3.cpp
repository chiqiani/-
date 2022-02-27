#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    Mat src=imread("/home/dqs/桌面/实验/1.jpeg");
    Mat deepMat,shallowMat;
    deepMat=src.clone();//深复制
    shallowMat=src;//浅复制
    uchar threshold=100;
    Vec3b p;
    int rows=src.rows;
    int cols=src.cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            p[0]=(src.at<Vec3b>(i,j)[0]+src.at<Vec3b>(i,j)[1]+src.at<Vec3b>(i,j)[2])/3;
            if(p[0]>threshold){
                p[0]=255;
            }
            else{
                p[0]=0;
            }
            src.at<Vec3b>(i,j)[0]=p[0];
            src.at<Vec3b>(i,j)[0]=p[0];
            src.at<Vec3b>(i,j)[0]=p[0];
            
        }
    }
    imshow("1",deepMat);
    imshow("2",shallowMat);
    imwrite("1-2-1.jpeg",deepMat);
    imwrite("1-2-2.jpeg",shallowMat);
    waitKey(0);
    return 0;
}
