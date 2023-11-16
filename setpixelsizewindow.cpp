#include "setpixelsizewindow.h"
#include "startupwindow.h"
#include<QDebug>
#include<cmath>
#include "mainwindow.h"
#include "ui_setpixelsizewindow.h"
SetPixelSizeWindow::SetPixelSizeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetPixelSizeWindow)
{
    ui->setupUi(this);
    const QString currentPixelSize = "4";
    ui->heightLabel->setText(currentPixelSize);
    ui->widthLabel->setText(currentPixelSize);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    ui->verticalLayout_2->setAlignment(Qt::AlignHCenter);
}
void SetPixelSizeWindow::updateValues(int x, int y)
{
    ui->heightLabel->setText(QString::number(x));
    ui->widthLabel->setText(QString::number(y));
}
SetPixelSizeWindow::~SetPixelSizeWindow()
{
    delete ui;
}

void SetPixelSizeWindow::on_returnButton_clicked()
{
    StartupWindow * x = new StartupWindow();
    this->close();
    x->show();

}
void SetPixelSizeWindow::on_pixelIncrease_Button_clicked()
{
    if(currentPowerOfTwo == 9) return;
    currentPowerOfTwo ++;
    currentPixelSize = std::pow(2,currentPowerOfTwo);
    updateValues(currentPixelSize,currentPixelSize);
}


void SetPixelSizeWindow::on_pixelDecrease_Button_clicked()
{
    if(currentPowerOfTwo == 0) return;
    currentPowerOfTwo--;
    currentPixelSize = std::pow(2,currentPowerOfTwo);
    updateValues(currentPixelSize,currentPixelSize);
}


void SetPixelSizeWindow::on_confirmButton_clicked()
{
    MainWindow * x = new MainWindow(nullptr, currentPixelSize);
    this->close();
    x->show();
}

