#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int pixelSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, pixelSize);
    animationManager = new AnimationManager(ui->scrollArea, 32, 4, pixelSize); // 32 Is tmp frame count | 4 is tmp frame rate
    AnimationPreview  *animationPreview = new AnimationPreview(this);
    connect(ui->StartPreview, &QAction::triggered, animationPreview, &AnimationPreview::startPreview);
    connect(ui->startPreviewButton, &QPushButton::clicked, animationPreview, &AnimationPreview::startPreview);
    //connect(ui->StartPreview, &QAction::triggered, spriteCanvas, &SpriteCanvas::changePixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* -- Mouse Events -- */

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    spriteCanvas->mousePress(event->globalPosition().toPoint());
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    spriteCanvas->mouseMove(event->globalPosition().toPoint());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    spriteCanvas->mouseRelease();
}

/* -- Button Press Events -- */

void MainWindow::on_undoBtn_clicked()
{
    spriteCanvas->undoAction();
}

void MainWindow::on_redoBtn_clicked()
{
    spriteCanvas->redoAction();
}

void MainWindow::on_clearBtn_clicked()
{
    spriteCanvas->clearCanvas();
}



void MainWindow::on_colorBtn_clicked()
{
    QColorDialog colorSelectionWindow;
    QColor selectedColor = colorSelectionWindow.getColor();
    spriteCanvas->setPixelColor(selectedColor);
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

