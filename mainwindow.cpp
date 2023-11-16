#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int spriteSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , spriteSize(spriteSize)
{
    ui->setupUi(this);
    
    activeTool = new BrushTool();

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, spriteSize);

    animationManager = new AnimationManager(spriteCanvas, ui->scrollArea, spriteSize, true);
    fileSystem = new FileSystem(animationManager, spriteCanvas);

    AnimationPreview* animationPreview = new AnimationPreview(animationManager->framesPerSecond, animationManager->animationFrames, nullptr);

    connect(ui->StartPreview, &QAction::triggered, animationPreview, &AnimationPreview::startPreview);
    connect(ui->startPreviewButton, &QPushButton::clicked, animationPreview, &AnimationPreview::startPreview);

    connect(spriteCanvas, &SpriteCanvas::updatePreviewUi, animationManager, &AnimationManager::updateFramePreviewElements);
    connect(spriteCanvas, &SpriteCanvas::startAction, animationManager, &AnimationManager::startAction);
    connect(spriteCanvas, &SpriteCanvas::endAction, animationManager, &AnimationManager::endAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Choose Sprite"), "C://", "Sprite Editor Project (*.ssp);;");
    fileSystem->saveSprite(filename, spriteSize);
}


void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Sprite Editor Project (*.ssp);;");
    spriteSize = fileSystem->loadJson(filename);
}

/* -- Mouse Events -- */

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    activeTool->useTool(event, spriteCanvas, false);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    activeTool->useTool(event, spriteCanvas, true);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    spriteCanvas->mouseRelease();
}

/* -- Button Press Events -- */

void MainWindow::on_undoBtn_clicked()
{
    animationManager->undoAction();
}

void MainWindow::on_redoBtn_clicked()
{
    animationManager->redoAction();
}

void MainWindow::on_clearBtn_clicked()
{
    spriteCanvas->clearCanvas();
}

void MainWindow::on_colorBtn_clicked()
{
    QColorDialog colorSelectionWindow;
    QColor selectedColor = colorSelectionWindow.getColor();
    //colorPanelLabel
    QString formattedColor = selectedColor.name();
    ui->colorPickerFrame->setStyleSheet("* {background-color: " + formattedColor + "}");

    spriteCanvas->setPixelColor(selectedColor);
}

void MainWindow::on_addFrameBtn_clicked()
{
    animationManager->createNewFrame();
}

void MainWindow::on_removeFrameBtn_clicked()
{
    animationManager->removeFrame();
}

/* -- Preview Button Press Events -- */

void MainWindow::on_StartPreview_triggered()
{

    animationPreview->startPreview();
}

void MainWindow::on_startPreviewButton_clicked()
{
    animationPreview->startPreview();
}

void MainWindow::on_switchSizeButton_clicked()
{

}

void MainWindow::on_stopPreviewButton_clicked()
{

}

void MainWindow::on_brushToolButton_clicked()
{
    activeTool = new BrushTool();
}

void MainWindow::on_eraseToolButton_clicked()
{
    activeTool = new EraseTool();
}

void MainWindow::on_paintBucketToolButton_clicked()
{
    activeTool = new paintTool();
}
