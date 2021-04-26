#include "mainwindow.h"
#include "search.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat Searchclass::eyesearch(Mat frame1){

    CascadeClassifier classifiereye("./xml/haarcascade_eye.xml");

    vector<Rect> eye;
    classifiereye.detectMultiScale(frame1, eye);

    for(Rect rc: eye){
        rectangle(frame1, rc, Scalar(255, 0, 0), 2);
    }
    return frame1;
}

Mat Searchclass::facesearch(Mat frame1){

    CascadeClassifier classifierface("./xml/haarcascade_frontalface_alt.xml");

    vector<Rect> face;
    classifierface.detectMultiScale(frame1, face);

    for(Rect rc: face){
        rectangle(frame1, rc, Scalar(255, 0, 0), 2);
    }
    return frame1;
}

Mat Searchclass::upbodysearch(Mat frame1){

    CascadeClassifier classifierupper("./xml/haarcascade_upperbody.xml");

    vector<Rect> upperbody;
    classifierupper.detectMultiScale(frame1, upperbody);

    for(Rect rc: upperbody){
        rectangle(frame1, rc, Scalar(255, 0, 0), 2);
    }
    return frame1;
}


Mat Searchclass::downbodysearch(Mat frame1){

    CascadeClassifier classifierlower("./xml/haarcascade_lowerbody.xml");

    vector<Rect> lowerbody;
    classifierlower.detectMultiScale(frame1, lowerbody);

    for(Rect rc: lowerbody){
        rectangle(frame1, rc, Scalar(255, 0, 0), 2);
    }
    return frame1;
}


Mat Searchclass::fullbodysearch(Mat frame1){

    CascadeClassifier classifierfull("./xml/haarcascade_fullbody.xml");

    vector<Rect> fullbody;
    classifierfull.detectMultiScale(frame1, fullbody);

    for(Rect rc: fullbody){
        rectangle(frame1, rc, Scalar(255, 0, 0), 2);
    }
    return frame1;
}

