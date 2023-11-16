#include <QApplication>
#include "startupwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupWindow w;
    w.show();
    return a.exec();
}
