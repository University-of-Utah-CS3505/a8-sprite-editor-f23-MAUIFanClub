#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paintLabelSize = ui->spriteLabel->width();

    // Initialize Pixmap
    pMap = new QPixmap(spriteSize,spriteSize);
    pMap->fill(Qt::lightGray);

    painter.begin(pMap);

    // initializes sprite label pixel map to pMap
    ui->spriteLabel->setPixmap(pMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint paintLabelPos = ui->spriteLabel->pos();

    // Calculates mouse position relative to the paintLabel position.
    QPoint mousePos;
    mousePos.setX(event->pos().x() - paintLabelPos.x());
    mousePos.setY(event->pos().y() - paintLabelPos.y());

    // Checks to see if mouse cursor is outside of the sprite editor. If outside it returns.
    if ((mousePos.x() < 0 || mousePos.x() > paintLabelSize) ||
        (mousePos.y() < 0 || mousePos.y() > paintLabelSize))
    {
        return;
    }

    float pixelSize = (paintLabelSize/spriteSize);

    QPoint pixelPos;
    pixelPos.setX((mousePos.x() / pixelSize));
    pixelPos.setY((mousePos.y() / pixelSize));

    drawPixel(pixelPos);
}

void MainWindow::drawPixel(QPoint pixelPosition)
{
    QPen p;
    p.setColor(Qt::blue);
    p.setWidth(1);

    painter.setPen(p);

    painter.drawPoint(pixelPosition);

    // Updates the paintLabel image to the new canvas.
    ui->spriteLabel->setPixmap(pMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}
