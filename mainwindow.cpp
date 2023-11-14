#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, 64); // 64 is the testing size of the Sprite : 64x64
    animationManager = new AnimationManager(ui->scrollArea, 32, 4, 64);
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
