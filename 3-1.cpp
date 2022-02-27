#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/6.jpeg");
    cv::Mat jieguo=src.clone();
    cv::Mat dst1,dst2,dst3,dst4,labels,stats,centroids;
    cv::cvtColor(src,dst1,cv::COLOR_BGR2GRAY);//得到灰度图
    cv::threshold(dst1,dst2,127,255,cv::THRESH_BINARY_INV);//二值化
    cv::Mat element = getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));//创建自定义核
    cv::morphologyEx(dst2,dst3,cv::MORPH_OPEN,element);//开运算，去除小白点
    int nccomps=cv::connectedComponentsWithStats(dst3,labels,stats,centroids);//标记联通域
    std::vector<cv::Vec3b> color(nccomps+1);
    color[0]=cv::Vec3b(0,0,0);//背景颜色
    for(int i=1;i<nccomps;i++){
        if(1.0*stats.at<int>(i,cv::CC_STAT_WIDTH)/stats.at<int>(i,cv::CC_STAT_HEIGHT)>0.9 && 1.0*stats.at<int>(i,cv::CC_STAT_WIDTH)/stats.at<int>(i,cv::CC_STAT_HEIGHT)<1.1 && stats.at<int>(i,cv::CC_STAT_WIDTH)>40 &&  stats.at<int>(i,cv::CC_STAT_WIDTH)<150){//接近圆形且宽度符合要求
            color[i]=cv::Vec3b(0,255,255);//符合要求为黄色
        }
        else{
            color[i]=cv::Vec3b(255,255,255);//否则为白色
        }
    }
    dst3=cv::Mat::zeros(dst3.size(),CV_8UC3);
    for(int i=0;i<dst3.rows;i++){
        for(int j=0;j<dst3.cols;j++){
            int label=labels.at<int>(i,j);
            if(color[label]==cv::Vec3b(0,255,255)){
                src.at<cv::Vec3b>(i,j)=color[label];//原图目标上色

        }
    }
    }
      cv::imshow("src",src);
      cv::Mat tmg1,tmg,mask;
      cv::cvtColor(src,tmg1,cv::COLOR_BGR2HSV);//转化为hsv，src为roi待提取
      cv::inRange(tmg1,cv::Scalar(26,43,46),cv::Scalar(34,255,255),mask);//提取黄色区域
      //cv::bitwise_and(src, src,tmg,mask);
      jieguo.copyTo(tmg,mask);
    cv::imshow("1",tmg);
    cv::imwrite("3-1.jpeg",tmg);
    cv::waitKey();
    return 0;
    
}