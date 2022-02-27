#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
int main(){
	cv::Mat src=cv::imread("/home/dqs/桌面/实验/3.jpeg");
    cv::Mat src1,dst,labels,dst1,stats,centroids;
    cv::cvtColor(src,src1,cv::COLOR_BGR2GRAY);//将源图转化为单通道图像
    cv::threshold(src1,dst1,127,255,cv::THRESH_BINARY);//二值化
    cv::Mat element = getStructuringElement(cv::MORPH_RECT,cv::Size(6.95,6.95));//获取自定义核
    cv::morphologyEx(dst1,dst,cv::MORPH_CLOSE,element);//闭运算
    cv::imshow("dst0",dst);
    int nccomps=cv::connectedComponentsWithStats(dst,labels,stats,centroids);//标记联通域
    std::cout << "硬币的个数: " << nccomps-1 << std::endl;//输出联通域个数
    std::vector<cv::Vec3b> color(nccomps+1);//color（nccomps+1）储存nccomps个Vec3b类型的颜色
    color[0] = cv::Vec3b(0,0,0);//背景为黑色
    for(int i=1;i<nccomps;i++){
        color[i] = cv::Vec3b(rand()%255,rand()%255,rand()%255);//随机上色
        // if(stats.at<int>(i,cv::CC_STAT_AREA)<100){//若面积小于100，则抹去
        //     color[i] = cv::Vec3b(0,0,0);
        // }
    }
    dst=cv::Mat::zeros(dst.size(),CV_8UC3);//图像清空
    for(int i = 0;i<dst.rows;i++){
        for(int j = 0;j<dst.cols;j++){
            int label=labels.at<int>(i,j);//读取该点的label
            dst.at<cv::Vec3b>(i,j)=color[label];//上色
        }
    }
    for(int i = 1;i<nccomps;i++){
        if(color[i] != cv::Vec3b(0,0,0)){
            cv::Point p1,p2;
            p1.x=stats.at<int>(i,cv::CC_STAT_LEFT);
            p1.y=stats.at<int>(i,cv::CC_STAT_TOP);//p1为左上点坐标
            p2.x=stats.at<int>(i,cv::CC_STAT_LEFT)+stats.at<int>(i,cv::CC_STAT_WIDTH);
            p2.y=stats.at<int>(i,cv::CC_STAT_TOP)+stats.at<int>(i,cv::CC_STAT_HEIGHT);//p2为右下角坐标
            cv::rectangle(dst,p1,p2,cv::Scalar(255,255,255),1);
        }
    }

    cv::imshow("dst",dst);
    cv::imwrite("2-3-2.jpeg",dst);
    cv::waitKey();
    return 0;
    
}