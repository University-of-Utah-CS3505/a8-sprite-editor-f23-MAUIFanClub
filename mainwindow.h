#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <stack>
#include "undoredomanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using DrawAction = UndoRedoManager::DrawAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPainter painter;

    // Draws a pixel at a given position
    void drawPixel(QPoint pixelPosition);
private slots:
    void on_undoBtn_clicked();

    void on_redoBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    bool mouseOnSpriteCanvas(QPoint globalMousePos);
    QPoint getMouseLocalPos(QPoint globalMousePos, QPoint spriteCanvasPos);
    QPoint getPixelPosition(QPoint mousePos);

    bool drawing;

    UndoRedoManager* undoRedoManager;
};
#endif // MAINWINDOW_H
