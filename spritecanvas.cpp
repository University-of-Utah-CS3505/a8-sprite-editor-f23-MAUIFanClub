#include "spritecanvas.h"

SpriteCanvas::SpriteCanvas(QLabel *spriteCanvas, int spriteSize)
{
    spriteCanvasSize = spriteCanvas->width();
    this->spriteSize = spriteSize;

    spritePixmap = new QPixmap(spriteSize,spriteSize);
    spritePixmap->fill(Qt::lightGray);

    painter.begin(spritePixmap);
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));

    this->spriteCanvas = spriteCanvas;
}

void SpriteCanvas::mousePress(QPoint globalMousePos, bool isDraw)
{
    QPoint localMousePos = spriteCanvas->mapFromGlobal(globalMousePos);

    if (!mouseOnSpriteCanvas(localMousePos)) return;

    emit startAction();

    drawing = true;
    if(isDraw)
    {
        drawPixel(getPixelPosition(localMousePos));
    }
    else
    {
        erasePixel(getPixelPosition(localMousePos));
    }

}

void SpriteCanvas::mouseMove(QPoint globalMousePos, bool isDraw)
{
    QPoint localMousePos = spriteCanvas->mapFromGlobal(globalMousePos);

    if (!mouseOnSpriteCanvas(localMousePos) || !drawing) return;
    if(isDraw)
    {
        drawPixel(getPixelPosition(localMousePos));
    }
    else
    {
        erasePixel(getPixelPosition(localMousePos));
    }

}

void SpriteCanvas::mouseRelease()
{
    if (!drawing) return;

    emit endAction();

    drawing = false;

    lastDrawnPixel = QPoint(-1,-1);

    emit updatePreviewUi();
}

bool SpriteCanvas::mouseOnSpriteCanvas(QPoint localMousePos)
{
    return (localMousePos.x() >= 0 && localMousePos.x() <= spriteCanvasSize) &&
           (localMousePos.y() >= 0 && localMousePos.y() <= spriteCanvasSize);
}

QPoint SpriteCanvas::getPixelPosition(QPoint mousePos)
{
    float pixelSize = (spriteCanvasSize / spriteSize);

    QPoint pixelPos((mousePos.x() / pixelSize),(mousePos.y() / pixelSize));

    return pixelPos;
}

void SpriteCanvas::drawPixel(QPoint pixelPosition)
{
    if (pixelPosition == lastDrawnPixel) return;

    // Pen used for drawing on painter
    QPen p;
    p.setColor(pixelColor);
    p.setWidth(1);

    painter.setPen(p);

    // Draws to the sprite
    painter.drawPoint(pixelPosition);

    lastDrawnPixel = pixelPosition;

    // Updates the paintLabel image to the new canvas.
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::erasePixel(QPoint pixelPosition)
{
    if (pixelPosition == lastDrawnPixel) return;

    // Pen used for drawing on painter
    QPen p;
    p.setColor(Qt::lightGray);
    p.setWidth(1);

    painter.setPen(p);

    // Draws to the sprite
    painter.drawPoint(pixelPosition);

    lastDrawnPixel = pixelPosition;

    // Updates the paintLabel image to the new canvas.
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::clearCanvas()
{
    emit startAction();

    spritePixmap->fill(Qt::lightGray);

    emit endAction();

    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::changePixmap(QPixmap *newPixmap)
{
    spritePixmap = newPixmap;

    if (painter.isActive())
        painter.end();

    painter.begin(spritePixmap);
    spriteCanvas->setPixmap(spritePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}

void SpriteCanvas::setPixelColor(QColor color)
{
    pixelColor = color;
}

void SpriteCanvas::displayAnimationFrame(QPixmap *animationFramePixmap, bool actualSize)
{
    if (actualSize)
        spriteCanvas->setPixmap(animationFramePixmap->scaled(spriteSize, spriteSize, Qt::KeepAspectRatio, Qt::FastTransformation));
    else
        spriteCanvas->setPixmap(animationFramePixmap->scaled(spriteCanvasSize, spriteCanvasSize, Qt::KeepAspectRatio, Qt::FastTransformation));
}
