//Reviewed by: Joshua Daniels
#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QObject>
#include "mainwindow.h"
#include "setpixelsizewindow.h"

namespace Ui {
class StartupWindow;
}
//The class that brings up the startup window that will allow a user to open a project or start a new one and take them to the set sprite size canvas
class StartupWindow : public QMainWindow
{
    Q_OBJECT

public:
    //The constructor to start the startup window
    explicit StartupWindow(QWidget *parent = nullptr);
    //destructor
    ~StartupWindow();
signals:
    //The signal if the user chooses to open an existing project
    void loadJson(QString filepath);

private slots:
    //Slot to open an existing project. Goes to main window and gives the file prompt
    void on_openProjectButton_clicked();
    //slot to start a new project. goes to set sprite window
    void on_newProjectButton_clicked();

private:
    //The UI object
    Ui::StartupWindow *ui;
};

#endif // STARTUPWINDOW_H
