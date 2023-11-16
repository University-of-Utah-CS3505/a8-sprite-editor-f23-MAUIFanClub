//Reviewed by: Ahmed Abdalla
#ifndef SETPIXELSIZEWINDOW_H
#define SETPIXELSIZEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SetPixelSizeWindow;
}
//The window that pops up for a new project to set the pixel size
class SetPixelSizeWindow : public QMainWindow
{
    Q_OBJECT

public:
    //The constructor to create the window to allow the user to set the pixel size of a project
    explicit SetPixelSizeWindow(QWidget *parent = nullptr);
    //destructor
    ~SetPixelSizeWindow();

private slots:
    //Slot for when the return button is pressed, takes the user back to the main menu
    void on_returnButton_clicked();
    //Slot to increase the size of the sprite project by a power of 2
    void on_pixelIncrease_Button_clicked();
    //Slot to decrease the size of the sprite project by a power of 2
    void on_pixelDecrease_Button_clicked();
    //sends the selected sprite size to the mainwindow and creates and launches it
    void on_confirmButton_clicked();

private:
    //UI element for the window
    Ui::SetPixelSizeWindow *ui;
    //Updates the sprite size
    void updateValues(int width, int height);
    //variable for the default size
    int currentPixelSize = 4;
    //variable to hold the power we raise it to.
    int currentPowerOfTwo = 2;
};

#endif // SETPIXELSIZEWINDOW_H
