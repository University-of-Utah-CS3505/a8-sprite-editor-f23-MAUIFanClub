#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int spriteSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , spriteSize(spriteSize)
{
    ui->setupUi(this);

    activeTool = new BrushTool();
    activeToolBtn = ui->brushToolButton;
    activeToolBtn->setEnabled(false);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, spriteSize);

    animationManager = new AnimationManager(spriteCanvas, ui->scrollArea, spriteSize, true);
    fileSystem = new FileSystem(animationManager, spriteCanvas);

    ui->colorPanelLabel->setStyleSheet("* {background-color: black}");

    animationPreview = new AnimationPreview(
        animationManager->animationFrames,
        nullptr);
    connect(spriteCanvas,
            &SpriteCanvas::updatePreviewUi,
            animationManager,
            &AnimationManager::updateFramePreviewElements);
    connect(spriteCanvas,
            &SpriteCanvas::startAction,
            animationManager,
            &AnimationManager::startAction);
    connect(spriteCanvas, &SpriteCanvas::endAction, animationManager, &AnimationManager::endAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Choose Sprite"),
                                                    "C://",
                                                    "Sprite Editor Project (*.ssp);;");
    fileSystem->saveSprite(filename, spriteSize);
}

void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "C://",
                                                    "Sprite Editor Project (*.ssp);;");
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
    ui->colorPanelLabel->setStyleSheet("* {background-color: " + formattedColor + "}");

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


void MainWindow::on_startPreviewButton_clicked()
{
    animationPreview->startPreview(animationManager, false);
    ui->stopPreviewButton->setEnabled(true);
    ui->OneFPSButton->setEnabled(false);
    ui->TenFPSButton->setEnabled(false);
    ui->TwentyFPSButton->setEnabled(false);
    ui->ThirtyFPSButton->setEnabled(false);
    ui->startPreviewButton->setEnabled(false);
    ui->switchSizeButton->setEnabled(false);
}


void MainWindow::on_stopPreviewButton_clicked() {

    animationPreview->stopPreview();
    ui->stopPreviewButton->setEnabled(false);
    ui->OneFPSButton->setEnabled(true);
    ui->TenFPSButton->setEnabled(true);
    ui->TwentyFPSButton->setEnabled(true);
    ui->ThirtyFPSButton->setEnabled(true);
    ui->startPreviewButton->setEnabled(true);
    ui->switchSizeButton->setEnabled(true);
}

void MainWindow::on_switchSizeButton_clicked() {
    animationPreview->startPreview(animationManager, true);
    ui->stopPreviewButton->setEnabled(true);
    ui->OneFPSButton->setEnabled(false);
    ui->TenFPSButton->setEnabled(false);
    ui->TwentyFPSButton->setEnabled(false);
    ui->ThirtyFPSButton->setEnabled(false);
    ui->startPreviewButton->setEnabled(false);
    ui->switchSizeButton->setEnabled(false);
}

void MainWindow::on_brushToolButton_clicked()
{
    activeToolBtn->setEnabled(true);

    activeTool = new BrushTool();
    activeToolBtn = ui->brushToolButton;
    activeToolBtn->setEnabled(false);
}

void MainWindow::on_eraseToolButton_clicked()
{
    activeToolBtn->setEnabled(true);

    activeTool = new EraseTool();
    activeToolBtn = ui->eraseToolButton;
    activeToolBtn->setEnabled(false);
}

void MainWindow::on_paintBucketToolButton_clicked()
{
    activeToolBtn->setEnabled(true);

    activeTool = new paintTool();
    activeToolBtn = ui->paintBucketToolButton;
    activeToolBtn->setEnabled(false);
}

void MainWindow::on_OneFPSButton_clicked()
{
    animationManager->framesPerSecond = 1;
}


void MainWindow::on_TenFPSButton_clicked()
{
    animationManager->framesPerSecond = 10;
}


void MainWindow::on_TwentyFPSButton_clicked()
{
    animationManager->framesPerSecond = 20;
}


void MainWindow::on_ThirtyFPSButton_clicked()
{
    animationManager->framesPerSecond = 30;
}
