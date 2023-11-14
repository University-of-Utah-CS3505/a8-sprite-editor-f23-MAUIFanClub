#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <stack>
#include "undoredomanager.h"
#include "spritecanvas.h"
#include "animationmanager.h"

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
private slots:
    void on_undoBtn_clicked();
    void on_redoBtn_clicked();
    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;

    SpriteCanvas *spriteCanvas;
    AnimationManager *animationManager;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
