#ifndef SPRITECANVAS_H
#define SPRITECANVAS_H

#include <QPoint>
#include <QPixmap>
#include <QLabel>
#include <QMouseEvent>
#include "undoredomanager.h"
#include <QDebug>

class SpriteCanvas
{
public:
    UndoRedoManager* undoRedoManager;
    SpriteCanvas(QLabel *spriteCanvas, int spriteSize);

    void mousePress(QPoint globalMousePos);
    void mouseMove(QPoint globalMousePos);
    void mouseRelease();

    void setPixelColor(QColor color);
    void clearCanvas();

    void undoAction();
    void redoAction();
private:
    QPixmap *spritePixmap;
    QPainter painter;
    QLabel *spriteCanvas;
    QColor pixelColor;

    int spriteCanvasSize;
    int spriteSize;

    // Draws a pixel at a given position
    void drawPixel(QPoint pixelPosition);

    bool mouseOnSpriteCanvas(QPoint globalMousePos);
    QPoint getMouseLocalPos(QPoint globalMousePos, QPoint spriteCanvasPos);
    QPoint getPixelPosition(QPoint mousePos);

    bool drawing;
};

#endif // SPRITECANVAS_H
