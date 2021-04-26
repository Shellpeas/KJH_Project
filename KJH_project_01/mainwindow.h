#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>

#include "histogram.h"
#include "rec.h"
#include "linedetection.h"
#include "colorchange.h"
#include "search.h"
#include "detecting.h"

#include "opencv2/opencv.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_connectbt_pressed();
    void on_RECbutton_pressed();
    void on_RGBchannel_pressed();
    void on_facebutton_pressed();
    void on_eyebutton_pressed();
    void on_upbody_pressed();
    void on_downbody_pressed();
    void on_fullbody_pressed();
    void on_Linedetection_pressed();
    void on_upbutton_pressed();
    void on_downbutton_pressed();
    void on_leftbutton_pressed();
    void on_rightbutton_pressed();
    void on_Refrash_pressed();
    void on_leftround_pressed();
    void on_rightround_pressed();
    void on_Expansion_pressed();
    void on_Reduce_pressed();
    void on_Capture_pressed();
    void on_Edgedetection_pressed();
    void on_Cornerdetection_pressed();
    void on_Fouriertransform_pressed();

private:
    Ui::MainWindow *ui;

    QGraphicsPixmapItem pixItem;
    QGraphicsPixmapItem pixItem2;
    QGraphicsPixmapItem pixItem3;
    QGraphicsPixmapItem pixItem4;
    QGraphicsPixmapItem pixItemRGB;
    QGraphicsPixmapItem pixItemDET;
    QGraphicsPixmapItem pixItemSearch;
    cv::VideoCapture video;

};




#endif // MAINWINDOW_H
