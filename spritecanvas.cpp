#include "spritecanvas.h"

SpriteCanvas::SpriteCanvas(QLabel *spriteCanvas, int spriteSize)
{
    spriteCanvasSize = spriteCanvas->width();
    this->spriteSize = spriteSize;

    spritePixmap = new QPixmap(spriteSize,spriteSize);
    spritePixmap->fill(Qt::lightGray);

    painter.begin(spritePixmap);
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));

    undoRedoManager = new UndoRedoManager();

    this->spriteCanvas = spriteCanvas;
}

void SpriteCanvas::mousePress(QPoint globalMousePos)
{
    QPoint mousePos = getMouseLocalPos(globalMousePos, spriteCanvas->pos());

    if (!mouseOnSpriteCanvas(mousePos)) return;

    undoRedoManager->StartAction(*spritePixmap);
    drawing = true;

    drawPixel(getPixelPosition(mousePos));
}

void SpriteCanvas::mouseMove(QPoint globalMousePos)
{
    QPoint mousePos = getMouseLocalPos(globalMousePos, spriteCanvas->pos());

    if (!mouseOnSpriteCanvas(mousePos) || !drawing) return;

    drawPixel(getPixelPosition(mousePos));
}

void SpriteCanvas::mouseRelease()
{
    if (!drawing) return;

    undoRedoManager->EndAction(*spritePixmap);
    drawing = false;
}

QPoint SpriteCanvas::getMouseLocalPos(QPoint globalMousePos, QPoint spriteCanvasPos)
{
    QPoint mousePos;
    mousePos.setX(globalMousePos.x() - spriteCanvasPos.x());
    mousePos.setY(globalMousePos.y() - spriteCanvasPos.y());

    return mousePos;
}

bool SpriteCanvas::mouseOnSpriteCanvas(QPoint localMousePos)
{
    return (localMousePos.x() >= 0 && localMousePos.x() <= spriteCanvasSize) &&
           (localMousePos.y() >= 0 && localMousePos.y() <= spriteCanvasSize);
}

QPoint SpriteCanvas::getPixelPosition(QPoint mousePos)
{
    float pixelSize = (spriteCanvasSize/spriteSize);

    QPoint pixelPos;
    pixelPos.setX((mousePos.x() / pixelSize));
    pixelPos.setY((mousePos.y() / pixelSize));

    return pixelPos;
}

void SpriteCanvas::drawPixel(QPoint pixelPosition)
{
    QPen p;
    p.setColor(pixelColor);
    p.setWidth(1);

    painter.setPen(p);

    // Draws to the sprite
    painter.drawPoint(pixelPosition);

    // Updates the paintLabel image to the new canvas.
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::clearCanvas()
{
    undoRedoManager->StartAction(*spritePixmap);

    spritePixmap->fill(Qt::lightGray);

    undoRedoManager->EndAction(*spritePixmap);

    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::setPixelColor(QColor color)
{
    pixelColor = color;
}

void SpriteCanvas::undoAction()
{
    undoRedoManager->undo(&painter, spriteCanvas, spritePixmap, spriteCanvasSize);
}

void SpriteCanvas::redoAction()
{
    undoRedoManager->redo(&painter, spriteCanvas, spritePixmap, spriteCanvasSize);
}
