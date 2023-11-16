#include "setpixelsizewindow.h"
#include <QDebug>
#include "mainwindow.h"
#include "startupwindow.h"
#include "ui_setpixelsizewindow.h"
#include <cmath>
setPixelSizeWindow::setPixelSizeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::setPixelSizeWindow)
{
    ui->setupUi(this);
    const QString currentPixelSize = "4";
    ui->heightLabel->setText(currentPixelSize);
    ui->widthLabel->setText(currentPixelSize);
    ui->verticalLayout->setAlignment(Qt::AlignCenter);
    ui->verticalLayout_2->setAlignment(Qt::AlignHCenter);
}
void setPixelSizeWindow::updateValues(int x, int y)
{
    ui->heightLabel->setText(QString::number(x));
    ui->widthLabel->setText(QString::number(y));
}
setPixelSizeWindow::~setPixelSizeWindow()
{
    delete ui;
}

void setPixelSizeWindow::on_returnButton_clicked()
{
    StartupWindow *x = new StartupWindow();
    this->close();
    x->show();
}
void setPixelSizeWindow::on_pixelIncrease_Button_clicked()
{
    if (currentPowerOfTwo == 9)
        return;
    currentPowerOfTwo++;
    currentPixelSize = std::pow(2, currentPowerOfTwo);
    updateValues(currentPixelSize, currentPixelSize);
}

void setPixelSizeWindow::on_pixelDecrease_Button_clicked()
{
    if (currentPowerOfTwo == 0)
        return;
    currentPowerOfTwo--;
    currentPixelSize = std::pow(2, currentPowerOfTwo);
    updateValues(currentPixelSize, currentPixelSize);
}

void setPixelSizeWindow::on_confirmButton_clicked()
{
    MainWindow *x = new MainWindow(nullptr, currentPixelSize);
    this->close();
    x->show();
}
