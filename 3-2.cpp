#include<iostream>
#include<opencv2/opencv.hpp>
int main(){
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/7.jpeg");
    cv::Mat tmg=src.clone();
    cv::Mat tmgroi;
    cv::Mat dst1,dst2,dst3,dst4,labels,stats,centroids;
    cv::cvtColor(src,dst1,cv::COLOR_BGR2GRAY);//转化为灰度图
    cv::threshold(dst1,dst2,127,255,cv::THRESH_BINARY);//二值化
    cv::Mat element = getStructuringElement(cv::MORPH_RECT,cv::Size(4,4));//创建自定义核
    cv::morphologyEx(dst2,dst3,cv::MORPH_OPEN,element);//开运算
    int nccomps=cv::connectedComponentsWithStats(dst3,labels,stats,centroids);//标记联通域
    for(int i=1;i<nccomps;i++){
        if(fabs(1.0*stats.at<int>(i,cv::CC_STAT_WIDTH)/stats.at<int>(i,cv::CC_STAT_HEIGHT)-1)<0.1 &&  stats.at<int>(i,cv::CC_STAT_WIDTH)>70){//宽高之比接近1且宽度大于70
            cv::Point p1,p2;
            p1.x=stats.at<int>(i,cv::CC_STAT_LEFT);
            p1.y=stats.at<int>(i,cv::CC_STAT_TOP);//p1为左上点坐标
            p2.x=stats.at<int>(i,cv::CC_STAT_LEFT)+stats.at<int>(i,cv::CC_STAT_WIDTH);
            p2.y=stats.at<int>(i,cv::CC_STAT_TOP)+stats.at<int>(i,cv::CC_STAT_HEIGHT);//p2为右下角坐标
            cv::Rect r1(p1.x,p1.y,stats.at<int>(i,cv::CC_STAT_WIDTH),stats.at<int>(i,cv::CC_STAT_HEIGHT));
            tmgroi=tmg(r1);
            cv::rectangle(src,p1,p2,cv::Scalar(0,255,255),2);//在原图上绘制矩形
        }
    }
    cv::imshow("roi",tmgroi);
    cv::imshow("dst3",tmg);
    cv::imshow("src",src);
    cv::imwrite("3-2.jpeg",tmgroi);  
    cv::waitKey();
    return 0;
}