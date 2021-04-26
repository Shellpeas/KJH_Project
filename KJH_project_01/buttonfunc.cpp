#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_RECbutton_pressed()
{
    if(ui->RECbutton->text()=="REC")
    {
        ui->RECbutton->setText("STOP");
        ui->RECbutton->setStyleSheet("#RECbutton{background-color:green; color:white; border-radius: 10px; padding: 2px; font: bold italic 32px;}");
    }
    else{
        ui->RECbutton->setText("REC");
        ui->RECbutton->setStyleSheet("#RECbutton{background-color:red; color:white; border-radius: 10px; padding: 2px; font: bold italic 32px;}");
    }
}


void MainWindow::on_Capture_pressed()
{


}


void MainWindow::on_RGBchannel_pressed()
{
    if(ui->RGBchannel->text() == "3channel")
    {
        ui->RGBchannel->setText("1channel");
    }
    else{
        ui->RGBchannel->setText("3channel");
    }
}


void MainWindow::on_facebutton_pressed()
{
    if(ui->facebutton->text()=="Face On"){
        ui->facebutton->setText("Face Off");
        ui->facebutton->setStyleSheet("#facebutton{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{ui->facebutton->setText("Face On");
        ui->facebutton->setStyleSheet("#facebutton{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }

}

void MainWindow::on_eyebutton_pressed()
{
    if(ui->eyebutton->text()=="Eye On"){
        ui->eyebutton->setText("Eye Off");
        ui->eyebutton->setStyleSheet("#eyebutton{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{ui->eyebutton->setText("Eye On");
        ui->eyebutton->setStyleSheet("#eyebutton{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}

void MainWindow::on_upbody_pressed()
{
    if(ui->upbody->text()=="Upperbody On"){
        ui->upbody->setText("Upperbody Off");
        ui->upbody->setStyleSheet("#upbody{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{ui->upbody->setText("Upperbody On");
        ui->upbody->setStyleSheet("#upbody{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}

void MainWindow::on_downbody_pressed()
{
    if(ui->downbody->text()=="Lowerbody On"){
        ui->downbody->setText("Lowerbody Off");
        ui->downbody->setStyleSheet("#downbody{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{ui->downbody->setText("Lowerbody On");
        ui->downbody->setStyleSheet("#downbody{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}

void MainWindow::on_fullbody_pressed()
{
    if(ui->fullbody->text()=="Fullbody On"){
        ui->fullbody->setText("Fullbody Off");
        ui->fullbody->setStyleSheet("#fullbody{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{ui->fullbody->setText("Fullbody On");
        ui->fullbody->setStyleSheet("#fullbody{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");

    }
}

void MainWindow::on_Linedetection_pressed()
{
    if(ui->Linedetection->text()=="Line\nDetection On")
    {
        ui->Linedetection->setText("Line\nDetection Off");
        ui->Linedetection->setStyleSheet("#Linedetection{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{
        ui->Linedetection->setText("Line\nDetection On");
        ui->Linedetection->setStyleSheet("#Linedetection{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }

}

void MainWindow::on_Edgedetection_pressed()
{
    if(ui->Edgedetection->text()=="Edge\nDetection On")
    {
        ui->Edgedetection->setText("Edge\nDetection Off");
        ui->Edgedetection->setStyleSheet("#Edgedetection{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{
        ui->Edgedetection->setText("Edge\nDetection On");
        ui->Edgedetection->setStyleSheet("#Edgedetection{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}

void MainWindow::on_Cornerdetection_pressed()
{
    if(ui->Cornerdetection->text()=="Corner\nDetection On")
    {
        ui->Cornerdetection->setText("Corner\nDetection Off");
        ui->Cornerdetection->setStyleSheet("#Cornerdetection{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{
        ui->Cornerdetection->setText("Corner\nDetection On");
        ui->Cornerdetection->setStyleSheet("#Cornerdetection{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }
}

void MainWindow::on_Fouriertransform_pressed()
{
    if(ui->Fouriertransform->text()=="Fourier\nTransform On")
    {
        ui->Fouriertransform->setText("Fourier\nTransform Off");
        ui->Fouriertransform->setStyleSheet("#Fouriertransform{padding: 2px; background-color: red; font: bold italic 15px; color:white;}");
    }
    else{
        ui->Fouriertransform->setText("Fourier\nTransform On");
        ui->Fouriertransform->setStyleSheet("#Fouriertransform{padding: 2px; background-color: green; font: bold italic 15px; color:white;}");
    }

}







// 위젯 이동
#define I 4


void MainWindow::on_upbutton_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x(), ui->mainvideo->y()-I);
}

void MainWindow::on_downbutton_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x(), ui->mainvideo->y()+I);
}

void MainWindow::on_leftbutton_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x()-I, ui->mainvideo->y());
}

void MainWindow::on_rightbutton_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x()+I, ui->mainvideo->y());
}

void MainWindow::on_Refrash_pressed()
{
    ui->mainvideo->setGeometry(110, 70, 411, 261);
    ui->mainvideo->setFixedSize(411, 261);
}

// 위젯 확대, 축소, 회전

void MainWindow::on_leftround_pressed()
{
    ui->mainvideo->rotate(-10);
}

void MainWindow::on_rightround_pressed()
{
    ui->mainvideo->rotate(10);
}

void MainWindow::on_Expansion_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x()-1, ui->mainvideo->y()-2);
    ui->mainvideo->setFixedSize(ui->mainvideo->width()+2, ui->mainvideo->height()+4);
}

void MainWindow::on_Reduce_pressed()
{
    ui->mainvideo->move(ui->mainvideo->x()+1, ui->mainvideo->y()+2);
    ui->mainvideo->setFixedSize(ui->mainvideo->width()-2, ui->mainvideo->height()-4);
}


