#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int pixelSize)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    spriteCanvas = new SpriteCanvas(ui->spriteCanvas, pixelSize);
    animationManager = new AnimationManager(ui->scrollArea, 32, 4, pixelSize); // 32 Is tmp frame count | 4 is tmp frame rate
   // activeTool =
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_brushToolButton_clicked()
{
    activeTool = new brushTool();
}


void MainWindow::on_eraseToolButton_clicked()
{
    activeTool = new eraseTool();
}

