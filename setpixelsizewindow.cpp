#include "setpixelsizewindow.h"
#include "startupwindow.h"
#include<QDebug>
#include<cmath>
#include "mainwindow.h"
#include "ui_setpixelsizewindow.h"
setPixelSizeWindow::setPixelSizeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setPixelSizeWindow)
{
    ui->setupUi(this);
    const QString currentPixelSize = "4";
    ui->label_3->setText(currentPixelSize);
    ui->label_2->setText(currentPixelSize);
}
void setPixelSizeWindow::updateValues(int x, int y)
{
    ui->label_3->setText(QString::number(x));
    ui->label_2->setText(QString::number(y));
}
setPixelSizeWindow::~setPixelSizeWindow()
{
    delete ui;
}

void setPixelSizeWindow::on_pushButton_clicked()
{
    StartupWindow * x = new StartupWindow();
    this->close();
    x->show();

}
void setPixelSizeWindow::on_pushButton_3_clicked()
{
    if(currentPowerOfTwo == 8) return;
    currentPowerOfTwo ++;
    currentPixelSize = std::pow(2,currentPowerOfTwo);
    updateValues(currentPixelSize,currentPixelSize);
}


void setPixelSizeWindow::on_pushButton_4_clicked()
{
    if(currentPowerOfTwo == 2) return;
    currentPowerOfTwo--;
    currentPixelSize = std::pow(2,currentPowerOfTwo);
    updateValues(currentPixelSize,currentPixelSize);
}


void setPixelSizeWindow::on_pushButton_2_clicked()
{
    MainWindow * x = new MainWindow(nullptr, currentPixelSize);
    this->close();
    x->show();
}

