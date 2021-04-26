#include "mainwindow.h"
#include "rec.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


void Rec::recvideo(){
    double fps = 30;
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    Size size(320, 240);
    writer.open("./video_file.avi", fourcc, fps, size);
}


