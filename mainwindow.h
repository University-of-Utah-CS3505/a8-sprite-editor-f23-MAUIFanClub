#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "animationmanager.h"
#include "animationpreview.h"
#include "brushTool.h"
#include "eraseTool.h"
#include "fileSystem.h"
#include "painttool.h"
#include "spritecanvas.h"
#include "tool_parent.h"
#include "undoredomanager.h"
#include <stack>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

using DrawAction = UndoRedoManager::DrawAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int pixelSize = 4);
    ~MainWindow();
private slots:
    void on_undoBtn_clicked();
    void on_redoBtn_clicked();
    void on_clearBtn_clicked();
    void on_colorBtn_clicked();

    void on_startPreviewButton_clicked();

    void on_switchSizeButton_clicked();

    void on_stopPreviewButton_clicked();

    void on_brushToolButton_clicked();

    void on_eraseToolButton_clicked();

    void on_addFrameBtn_clicked();

    void on_removeFrameBtn_clicked();

    void on_actionSave_triggered();
    void on_OneFPSButton_clicked();

    void on_TenFPSButton_clicked();

    void on_TwentyFPSButton_clicked();

    void on_ThirtyFPSButton_clicked();

public slots:
    void on_actionLoad_triggered();

    void on_paintBucketToolButton_clicked();

private:
    Ui::MainWindow *ui;
    Tool_Parent *activeTool = new EraseTool();
    SpriteCanvas *spriteCanvas;
    AnimationManager *animationManager;
    FileSystem *fileSystem;
    AnimationPreview *animationPreview;

    QPushButton *activeToolBtn;

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    int spriteSize;
    int frameCount;
};
#endif // MAINWINDOW_H
