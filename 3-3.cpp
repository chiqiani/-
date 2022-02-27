#include<iostream>
#include<opencv2/opencv.hpp>
int main(){
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/8.jpeg");
    cv::Mat tmg=src.clone(),mask(src.size(),CV_8UC3,cv::Scalar(0,0,0)),tmgroi;
    cv::Mat dst1,dst2,dst3,dst4,labels,stats,centroids;
    cv::cvtColor(src,dst1,cv::COLOR_BGR2HSV);//转化为hsv
    std::vector<cv::Mat> channels;
    cv::split(dst1,channels);
    cv::threshold(channels[1],dst2,127,255,cv::THRESH_BINARY);//二值化
    cv::Mat element = getStructuringElement(cv::MORPH_RECT,cv::Size(4,4));//创建自定义核
    cv::morphologyEx(dst2,dst3,cv::MORPH_OPEN,element);//开运算
    int nccomps=cv::connectedComponentsWithStats(dst3,labels,stats,centroids);//标记联通域
    for(int i=1;i<nccomps;i++){
        if(fabs(1.0*stats.at<int>(i,cv::CC_STAT_WIDTH)/stats.at<int>(i,cv::CC_STAT_HEIGHT)-1)<0.5 &&  stats.at<int>(i,cv::CC_STAT_WIDTH)>50){//宽高之比接近1且宽度大于50
            cv::Point p1,p2;
            p1.x=stats.at<int>(i,cv::CC_STAT_LEFT);
            p1.y=stats.at<int>(i,cv::CC_STAT_TOP);//p1为左上点坐标
            p2.x=stats.at<int>(i,cv::CC_STAT_LEFT)+stats.at<int>(i,cv::CC_STAT_WIDTH);
            p2.y=stats.at<int>(i,cv::CC_STAT_TOP)+stats.at<int>(i,cv::CC_STAT_HEIGHT);//p2为右下角坐标
            cv::rectangle(mask,p1,p2,cv::Scalar(255,255,255),-1);//画出白色矩形
            cv::rectangle(src,p1,p2,cv::Scalar(0,255,255),2);//在原图上绘制矩形
        }
    }
    tmg.copyTo(tmgroi,mask);//mat&mat
    cv::imshow("1",channels[1]);
    cv::imshow("src",tmg);
    cv::imshow("roi",tmgroi);
    cv::imwrite("3-3-roi.jpeg",tmgroi);
    cv::imwrite("3-3-原图.jpeg",tmg);
    cv::waitKey();
    return 0;
}