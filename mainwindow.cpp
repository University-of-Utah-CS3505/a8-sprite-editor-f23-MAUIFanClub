#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, int pixelSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    spriteSize = pixelSize;
    connect(this, &MainWindow::saveSprite, &filesystem, &FileSystem::saveSprite);
    connect(this, &MainWindow::loadJson, &filesystem, &FileSystem::loadJson);
    ui->setupUi(this);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, pixelSize);
    animationManager = new AnimationManager(spriteCanvas, ui->scrollArea, 32, 4, pixelSize); // 32 Is tmp frame count | 4 is tmp frame rate
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

void MainWindow::on_actionSave_triggered()
{

    QString filename = QFileDialog::getSaveFileName(this, tr("Choose Sprite"), "C://", "Sprite Editor Project (*.ssp);;");
    emit saveSprite(filename, spriteSize);
}


void MainWindow::on_actionLoad_triggered()
{

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Sprite Editor Project (*.ssp);;");
    emit loadJson(filename);
}

