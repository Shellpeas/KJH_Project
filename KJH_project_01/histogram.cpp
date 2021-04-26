#include "mainwindow.h"
#include "histogram.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



void Histogram::ca_Histo(const Mat& image, Mat& hist, int bins, int range_max)
{
    int     histSize[] = {bins};
    float   range[] = { 0 , (float)range_max };
    int     channels[] = { 0 };
    const float* ranges[] = { range };

    calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);

}

Mat Histogram::make_palatte(int rows, int num)
{
    Mat hsv(rows, 1, CV_8UC3);
    for(int i = 0; i < rows; i++)
    {
        // uchar hue = saturate_cast<uchar>((float)i / rows * 180);
        if(num == 1){
                hsv.at<Vec3b>(i) = Vec3b(0, 0, 255);
        }
        else if(num == 2){
            hsv.at<Vec3b>(i) = Vec3b(0, 255, 0);
        }
        else if(num == 3){
            hsv.at<Vec3b>(i) = Vec3b(255, 0, 0);
        }
    }
    cvtColor(hsv, hsv, COLOR_BGR2RGB);
    return hsv;
}

void Histogram::draw_histo(Mat hist, Mat &hist_img, Size size, int a)
{
    Mat hsv_palatte = make_palatte(hist.rows, a);

    hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
    float  bin = (float)hist_img.cols / hist.rows;
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

    for (int i = 0; i<hist.rows; i++)
    {
        float start_x = (i * bin);
        float  end_x = (i + 1) * bin;
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at <float>(i));


        Scalar color = hsv_palatte.at<Vec3b>(i);
        if (pt2.y>0) rectangle(hist_img, pt1, pt2, color, -1);
    }
    flip(hist_img, hist_img, 0);

}


Mat Histogram::histg(Mat frame, int num)
{
    Mat BGR_arr[3];
    //    cvtColor(frame, HSV_img, COLOR_BGR2HSV);
    split(frame, BGR_arr);

    Mat hue_hist, hue_hist_img;

    if(num == 1){
        ca_Histo(BGR_arr[0], hue_hist, 256, 256);
        draw_histo(hue_hist, hue_hist_img, Size(256, 100), 1);
    }
    else if(num == 2){
        ca_Histo(BGR_arr[1], hue_hist, 256, 256);
        draw_histo(hue_hist, hue_hist_img, Size(256, 100), 2);
    }
    else if(num == 3){
        ca_Histo(BGR_arr[2], hue_hist, 256, 256);
        draw_histo(hue_hist, hue_hist_img, Size(256, 100), 3);
    }
    return hue_hist_img;
}
