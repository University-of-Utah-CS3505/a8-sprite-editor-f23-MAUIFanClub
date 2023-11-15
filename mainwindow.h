#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <QColor>
#include <stack>
#include "undoredomanager.h"
#include "spritecanvas.h"
#include "animationmanager.h"
#include <QFileDialog>
#include <QObject>
#include "fileSystem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using DrawAction = UndoRedoManager::DrawAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int pixelSize = 4);
    ~MainWindow();

signals:
    void loadJson(QString filepath);
    void saveSprite(QString filepath, int size);

private slots:
    void on_undoBtn_clicked();
    void on_redoBtn_clicked();
    void on_clearBtn_clicked();
    void on_colorBtn_clicked();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;

    SpriteCanvas *spriteCanvas;
    AnimationManager *animationManager;
    FileSystem *filesystem;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    int spriteSize;
    int frameCount;
};
#endif // MAINWINDOW_H
