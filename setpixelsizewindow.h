#ifndef SETPIXELSIZEWINDOW_H
#define SETPIXELSIZEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SetPixelSizeWindow;
}

class SetPixelSizeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetPixelSizeWindow(QWidget *parent = nullptr);
    ~SetPixelSizeWindow();

private slots:
    void on_returnButton_clicked();

    void on_pixelIncrease_Button_clicked();

    void on_pixelDecrease_Button_clicked();

    void on_confirmButton_clicked();

private:
    Ui::SetPixelSizeWindow *ui;
    void updateValues(int width, int height);
    int currentPixelSize = 4;
    int currentPowerOfTwo = 2;
};

#endif // SETPIXELSIZEWINDOW_H
