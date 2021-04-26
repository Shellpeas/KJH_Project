#ifndef LINESEARCH_H
#define LINESEARCH_H

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Linedetection
{
public:
    void draw_Lines(Mat image, Mat& dst, vector<Vec2f> lines, int nline);
    Mat Line_edge(Mat frame1);

    Mat canny_edge(Mat frame1);
    Mat corner(Mat frame1);

    Mat Fourier(Mat frame1);

};





#endif // LINESEARCH_H
