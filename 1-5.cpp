#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main(){
    VideoCapture capture(0);
    if(!capture.isOpened()){//判断是否打开摄像头
        cout<<"failture";
        return -1;

    }
    while(1){
        Mat src;
        capture>>src;
        if(!src.empty()){//判断是否读取图像成功
            imshow("1",src);//输出图像
        }
        if(waitKey(30)==27){//每30ms输出一帧，若按下“Eas”，则退出。
            break;
        }
    }
    return 0;
}
