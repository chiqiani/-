#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

void correction(const cv::Mat &src, cv::Mat &dst, double gamma);
int main() {
    cv::Mat src = cv::imread("/home/dqs/桌面/实验/2.jpeg");
    cv::Mat dst;
    correction(src,dst,0.5);
    cv::imshow("dst111",dst);
    cv::waitKey(0);
    return 0;
}
void correction(const cv::Mat& src, cv::Mat& dst, double gamma) {
    uchar lut[256];
    for (int i = 0; i < 256; i++)
    {
        lut[i] = std::pow(i / 255., gamma) * 255.;
    }
    dst = src.clone();
    int channels = src.channels();
    if(channels == 1) {
        for (auto iter = dst.begin<uchar>(), end = dst.end<uchar>(); iter != end; ++iter) {
            *iter=lut[(*iter)];
        }
    }
    else {
        for (auto iter = dst.begin<cv::Vec3b>(), end = dst.end<cv::Vec3b>(); iter != end; ++iter) {
            (*iter)[0] = lut[(*iter)[0]];
            (*iter)[1] = lut[(*iter)[1]];
            (*iter)[2] = lut[(*iter)[2]];
        }
    }
 }

