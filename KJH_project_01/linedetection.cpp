#include "mainwindow.h"
#include "linedetection.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void Linedetection::draw_Lines(Mat image, Mat &dst, vector<Vec2f> lines, int nline)
{
    if(image.channels() == 3) image.copyTo(dst);
    else cvtColor(image, dst, COLOR_GRAY2RGB);

    for(int i = 0; i < min((int)lines.size(), nline); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        double a = cos(theta), b = sin(theta);

        Point2d delta(1000 * -b, 1000 * a);
        Point2d pt(a*rho, b*rho);
        line(dst, pt + delta, pt - delta, Scalar(0, 255, 0), 1, LINE_AA);

    }
}


Mat Linedetection::Line_edge(Mat frame1)
{
    Mat lineframe;
    cvtColor(frame1, lineframe, COLOR_BGR2GRAY);
    double rho = 1, theta = CV_PI/180;
    Mat canny, dst1;
    GaussianBlur(lineframe, canny, Size(5,5), 2, 2);
    Canny(canny, canny, 100, 150, 3);
    vector<Vec2f> lines1;
    HoughLines(canny, lines1, rho, theta, 50);
    draw_Lines(canny, dst1, lines1, 10);

    return dst1;

}


Mat Linedetection::canny_edge(Mat frame1)
{
    Mat cannyedge;
    cvtColor(frame1, cannyedge, COLOR_BGR2GRAY);
    Mat canny, dst1;
    GaussianBlur(cannyedge, canny, Size(3,3), 0, 0);
    Canny(canny, canny, 50, 150, 3);
    vector<Vec2f> lines1;
    draw_Lines(canny, dst1, lines1, 10);

    return dst1;

}

Mat Linedetection::corner(Mat frame1)
{
    Mat src, dst, harris, harris_norm;
    cvtColor(frame1, src, COLOR_BGR2GRAY);

    cornerHarris(src, harris, 3, 3, 0.04);
    normalize(harris, harris_norm, 0, 255, NORM_MINMAX, CV_8U);
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for(int j=1; j<harris.rows - 1; j++){
        for(int i = 1; i < harris.cols - 1; i++){
            if(harris_norm.at<uchar>(j, i) > 120){
                if(harris.at<float>(j,i) > harris.at<float>(j-1, i) &&
                   harris.at<float>(j,i) > harris.at<float>(j+1, i) &&
                   harris.at<float>(j,i) > harris.at<float>(j, i-1) &&
                   harris.at<float>(j,i) > harris.at<float>(j, i+1)){
                    circle(dst, Point(i,j), 5, Scalar(0,255,0), 2);
                }
            }
        }
    }

    return dst;

}


Mat Linedetection::Fourier(Mat frame1){
    Mat dst;
    Mat src;
    cvtColor(frame1, src, COLOR_BGR2GRAY);

    Mat fImage;
    src.convertTo(fImage, CV_32F);

    Mat dftA;
    dft(fImage, dftA, DFT_COMPLEX_OUTPUT);

    Mat dftA2[2];
    split(dftA, dftA2);

    Mat magF;
    magnitude(dftA2[0], dftA2[1], magF);
    magF += Scalar(1);
    log(magF, magF);

    Mat magImage;
    normalize(magF, magImage, 0, 255, NORM_MINMAX, CV_8U);

    cvtColor(magImage, dst, COLOR_GRAY2BGR);

    return dst;
}


