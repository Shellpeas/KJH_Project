#ifndef REC_H
#define REC_H

#include "opencv2/opencv.hpp"
#include "mainwindow.h"

using namespace cv;
using namespace std;


class Rec{
public:
    VideoWriter writer;
public:
    void recvideo();


};

#endif // REC_H
