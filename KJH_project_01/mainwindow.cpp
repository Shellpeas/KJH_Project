#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainvideo->setScene(new QGraphicsScene(this));
    ui->mainvideo->scene()->addItem(&pixItem);

    ui->RedHisto->setScene(new QGraphicsScene(this));
    ui->RedHisto->scene()->addItem(&pixItem2);

    ui->GreenHisto->setScene(new QGraphicsScene(this));
    ui->GreenHisto->scene()->addItem(&pixItem3);

    ui->BlueHisto->setScene(new QGraphicsScene(this));
    ui->BlueHisto->scene()->addItem(&pixItem4);

    ui->RGBvideo->setScene(new QGraphicsScene(this));
    ui->RGBvideo->scene()->addItem(&pixItemRGB);

    ui->Detectionvideo->setScene(new QGraphicsScene(this));
    ui->Detectionvideo->scene()->addItem(&pixItemDET);

    ui->searchvideo->setScene(new QGraphicsScene(this));
    ui->searchvideo->scene()->addItem(&pixItemSearch);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connectbt_pressed()
{
    using namespace cv;
    if(video.isOpened())
    {
        ui->connectbt->setText("Connect");
        video.release();
        return;
    }


    bool isCamera;
    int cameraIndex = ui->cameranumedit->text().toInt(&isCamera);
    if(isCamera)
    {
        if(!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                                  "Camera not find",
                                  "Make sure you entered a correct camera number");
            return;
        }
    }
    else
    {
        if(!video.open(ui->cameranumedit->text().trimmed().toStdString()))
        {
            QMessageBox::critical(this,
                                  "Video Error",
                                  "Make sure you entered a correct and supported video file path");
            return;
        }
    }

    ui->connectbt->setText("Disconnect");

    Mat frame1;

    video.set(3, 320);
    video.set(4, 240);

    video >> frame1;

    static Rec *rec= new Rec;
    rec->recvideo();


    while(video.isOpened())
    {
        video >> frame1;
        Histogram histogram;
        if(!frame1.empty())
        {            
            cvtColor(frame1, frame1, COLOR_BGR2RGB);
            Mat red_hist, green_hist, blue_hist;


            // Mainvideo

            if(ui->tabWidget->currentIndex()==0){
                QImage qimg(frame1.data,
                            frame1.cols,
                            frame1.rows,
                            frame1.step,
                            QImage::Format_RGB888);

                pixItem.setPixmap(QPixmap::fromImage(qimg));
                ui->mainvideo->fitInView(&pixItem, Qt::KeepAspectRatio);


                //히스토그램

                red_hist = histogram.histg(frame1, 1);
                green_hist = histogram.histg(frame1, 2);
                blue_hist = histogram.histg(frame1, 3);

                if(ui->RECbutton->text()=="STOP")
                {
                    cvtColor(frame1, frame1, COLOR_RGB2BGR);
                    rec->writer << frame1;
                    waitKey(cvRound(400.0 / 30));
                }

            }

            // TAB2 - RGB

            if(ui->tabWidget->currentIndex()==1){
                bool redbool = ui->RedCheck->checkState();
                bool greenbool = ui->GreenCheck->checkState();
                bool bluebool = ui->BlueCheck->checkState();
                Colorchange colorchange;
                Mat frame2;

                // 3채널

                if(ui->RGBchannel->text() == "3channel")
                {
                    frame2 = colorchange.colorch(frame1, 1, redbool, greenbool, bluebool);
                }
                else{
                    frame2 = colorchange.colorch(frame1, 3, redbool, greenbool, bluebool);
                }

                QImage qimgRGB(frame2.data,
                               frame2.cols,
                               frame2.rows,
                               frame2.step,
                               QImage::Format_RGB888);

                pixItemRGB.setPixmap(QPixmap::fromImage(qimgRGB));
                ui->RGBvideo->fitInView(&pixItemRGB, Qt::KeepAspectRatio);

                //히스토그램
                red_hist = histogram.histg(frame2, 1);
                green_hist = histogram.histg(frame2, 2);
                blue_hist = histogram.histg(frame2, 3);
            }

            // TAB2 end

            // TAB3 detecting

            if(ui->tabWidget->currentIndex()==2){

                if(ui->eyebutton->text() == "Eye Off"){
                    Searchclass searchimg;
                    frame1 = searchimg.eyesearch(frame1);
                }
                if(ui->facebutton->text() == "Face Off"){
                    Searchclass searchimg;
                    frame1 = searchimg.facesearch(frame1);
                }
                if(ui->upbody->text() == "Upperbody Off"){
                    Searchclass searchimg;
                    frame1 = searchimg.upbodysearch(frame1);
                }
                if(ui->downbody->text() == "Lowerbody Off"){
                    Searchclass searchimg;
                    frame1 = searchimg.downbodysearch(frame1);
                }
                if(ui->fullbody->text() == "Fullbody Off"){
                    Searchclass searchimg;
                    frame1 = searchimg.fullbodysearch(frame1);
                }

                QImage qimgSearch(frame1.data,
                                  frame1.cols,
                                  frame1.rows,
                                  frame1.step,
                                  QImage::Format_RGB888);
                pixItemSearch.setPixmap(QPixmap::fromImage(qimgSearch));
                ui->searchvideo->fitInView(&pixItemSearch, Qt::KeepAspectRatio);

                red_hist = histogram.histg(frame1, 1);
                green_hist = histogram.histg(frame1, 2);
                blue_hist = histogram.histg(frame1, 3);
            }

            // TAP3 end

            // TAB4

            if(ui->Linedetection->text()=="Line\nDetection Off")
            {
                Linedetection linedetect;
                frame1 = linedetect.Line_edge(frame1);
            }

           if(ui->Edgedetection->text()=="Edge\nDetection Off")
           {
               Linedetection cannyedge;
               frame1 = cannyedge.canny_edge(frame1);

           }

            if(ui->Cornerdetection->text()=="Corner\nDetection Off")
            {
                Linedetection cornerdetect;
                frame1 = cornerdetect.corner(frame1);
            }

            if(ui->Fouriertransform->text()=="Fourier\nTransform Off")
            {
                Linedetection fourier;
                frame1 = fourier.Fourier(frame1);
            }





            QImage qimgSearch(frame1.data,
                              frame1.cols,
                              frame1.rows,
                              frame1.step,
                              QImage::Format_RGB888);
            pixItemDET.setPixmap(QPixmap::fromImage(qimgSearch));
            ui->Detectionvideo->fitInView(&pixItemDET, Qt::KeepAspectRatio);


            red_hist = histogram.histg(frame1, 1);
            green_hist = histogram.histg(frame1, 2);
            blue_hist = histogram.histg(frame1, 3);


            // Histogram draw

            QImage qimg2(red_hist.data,
                         red_hist.cols,
                         red_hist.rows,
                         red_hist.step,
                         QImage::Format_RGB888);

            QImage qimg3(green_hist.data,
                         green_hist.cols,
                         green_hist.rows,
                         green_hist.step,
                         QImage::Format_RGB888);

            QImage qimg4(blue_hist.data,
                         blue_hist.cols,
                         blue_hist.rows,
                         blue_hist.step,
                         QImage::Format_RGB888);

            pixItem2.setPixmap(QPixmap::fromImage(qimg2));
            ui->RedHisto->fitInView(&pixItem2, Qt::KeepAspectRatio);\
            pixItem3.setPixmap(QPixmap::fromImage(qimg3));
            ui->GreenHisto->fitInView(&pixItem3, Qt::KeepAspectRatio);
            pixItem4.setPixmap(QPixmap::fromImage(qimg4));
            ui->BlueHisto->fitInView(&pixItem4, Qt::KeepAspectRatio);

        }

        qApp->processEvents();
    }

}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(video.isOpened())
    {
        QMessageBox::warning(this,
                             "Warning",
                             "Stop the video before closing the application!");
        event->ignore();
    }
    else
    {
        event->accept();
    }
}




