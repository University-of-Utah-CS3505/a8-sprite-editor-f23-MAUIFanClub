#ifndef STARTUPWINDOW_H
#define STARTUPWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QObject>
#include "fileSystem.h"
#include "mainwindow.h"

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
    FileSystem *filesystem;
};

#endif // STARTUPWINDOW_H
