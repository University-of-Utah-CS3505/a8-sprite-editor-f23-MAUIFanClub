#ifndef SETPIXELSIZEWINDOW_H
#define SETPIXELSIZEWINDOW_H

#include <QMainWindow>

namespace Ui {
class setPixelSizeWindow;
}

class setPixelSizeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit setPixelSizeWindow(QWidget *parent = nullptr);
    ~setPixelSizeWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::setPixelSizeWindow *ui;
    void updateValues(int width, int height);
    int currentPixelSize = 4;
    bool adjustSpinBoxValue = true;
    int currentPowerOfTwo = 2;
};

#endif // SETPIXELSIZEWINDOW_H
