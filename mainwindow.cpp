#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int spriteSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , spriteSize(spriteSize)
{

    ui->setupUi(this);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, spriteSize);
    animationManager = new AnimationManager(spriteCanvas, ui->scrollArea, 3, 4, spriteSize); // 1 Is tmp frame count | 4 is tmp frame rate
    filesystem = new FileSystem(animationManager, spriteCanvas);
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
    filesystem->saveSprite(filename, spriteSize);
}
void MainWindow::on_actionLoad_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Sprite Editor Project (*.ssp);;");
    filesystem->loadJson(filename);
}
