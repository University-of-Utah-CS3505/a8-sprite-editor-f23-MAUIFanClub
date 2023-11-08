#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Draws a pixel at a given position
    void drawPixel(QPoint pixelPosition);
private:
    Ui::MainWindow *ui;

    QPainter painter;
    QPixmap *pMap;

    int spriteSize = 64; // assigned manually for now.
    int paintLabelSize;

    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
