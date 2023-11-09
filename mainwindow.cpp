#include "mainwindow.h"
#include "./ui_mainwindow.h"

QPixmap *pMap;

int spriteSize = 64;
int paintLabelSize = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paintLabelSize = ui->spriteCanvas->width();

    pMap = new QPixmap(spriteSize,spriteSize);
    pMap->fill(Qt::lightGray);

    painter.begin(pMap);
    ui->spriteCanvas->setPixmap(pMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));

    undoRedoManager = new UndoRedoManager();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Mouse Pressed
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint mousePos = getMouseLocalPos(event->pos(), ui->spriteCanvas->pos());

    if (!mouseOnSpriteCanvas(mousePos)) return;

    undoRedoManager->StartAction(*pMap);
    drawing = true;

    drawPixel(getPixelPosition(mousePos));
}

// Mouse Clicked and Moving
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint mousePos = getMouseLocalPos(event->pos(), ui->spriteCanvas->pos());

    if (!mouseOnSpriteCanvas(mousePos) || !drawing) return;

    drawPixel(getPixelPosition(mousePos));
}

// Mouse Released
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (!drawing) return;

    undoRedoManager->EndAction(*pMap);
    drawing = false;
}

QPoint MainWindow::getMouseLocalPos(QPoint globalMousePos, QPoint spriteCanvasPos)
{
    QPoint mousePos;
    mousePos.setX(globalMousePos.x() - spriteCanvasPos.x());
    mousePos.setY(globalMousePos.y() - spriteCanvasPos.y());

    return mousePos;
}

bool MainWindow::mouseOnSpriteCanvas(QPoint localMousePos)
{
    return (localMousePos.x() >= 0 && localMousePos.x() <= paintLabelSize) &&
           (localMousePos.y() >= 0 && localMousePos.y() <= paintLabelSize);
}

QPoint MainWindow::getPixelPosition(QPoint mousePos)
{
    float pixelSize = (paintLabelSize/spriteSize);

    QPoint pixelPos;
    pixelPos.setX((mousePos.x() / pixelSize));
    pixelPos.setY((mousePos.y() / pixelSize));

    return pixelPos;
}

void MainWindow::drawPixel(QPoint pixelPosition)
{
    QPen p;
    p.setColor(Qt::blue);
    p.setWidth(1);

    painter.setPen(p);

    // Draws to the sprite
    painter.drawPoint(pixelPosition);

    // Updates the paintLabel image to the new canvas.
    ui->spriteCanvas->setPixmap(pMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void MainWindow::on_undoBtn_clicked()
{
    undoRedoManager->Undo(&painter, ui->spriteCanvas, pMap, paintLabelSize);
}


void MainWindow::on_redoBtn_clicked()
{
    undoRedoManager->Redo(&painter, ui->spriteCanvas, pMap, paintLabelSize);
}

// Fills the pixmap lightGray
void MainWindow::on_clearBtn_clicked()
{
    undoRedoManager->StartAction(*pMap);

    pMap->fill(Qt::lightGray);

    undoRedoManager->EndAction(*pMap);

    ui->spriteCanvas->setPixmap(pMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

