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

class StartupWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartupWindow(QWidget *parent = nullptr);
    ~StartupWindow();
signals:
    void loadJson(QString filepath);

private slots:
    void on_openProjectButton_clicked();

    void on_newProjectButton_clicked();

private:
    Ui::StartupWindow *ui;
};

#endif // STARTUPWINDOW_H
