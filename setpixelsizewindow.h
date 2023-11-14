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
    void on_returnButton_clicked();

    void on_pixelIncrease_Button_clicked();

    void on_pixelDecrease_Button_clicked();

    void on_confirmButton_clicked();

private:
    Ui::setPixelSizeWindow *ui;
    void updateValues(int width, int height);
    int currentPixelSize = 4;
    int currentPowerOfTwo = 2;
};

#endif // SETPIXELSIZEWINDOW_H
