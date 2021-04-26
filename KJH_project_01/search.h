#ifndef SEARCH_H
#define SEARCH_H
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


class Searchclass
{
public:
    Mat eyesearch(Mat frame1);
    Mat facesearch(Mat frame1);
    Mat upbodysearch(Mat frame1);
    Mat downbodysearch(Mat frame1);
    Mat fullbodysearch(Mat frame1);
};


#endif // SEARCH_H
