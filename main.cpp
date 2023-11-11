#include "mainwindow.h"
#include "startupwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupWindow w;
    w.show();
    return a.exec();
}
