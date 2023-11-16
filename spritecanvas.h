#ifndef SPRITECANVAS_H
#define SPRITECANVAS_H

#include <QPainter>
#include <QPoint>
#include <QPixmap>
#include <QLabel>
#include <QPointF>
#include <QColor>
#include <QMouseEvent>
#include <QDebug>

class SpriteCanvas : public QObject
{
    Q_OBJECT
public:
    SpriteCanvas(QLabel *spriteCanvas, int spriteSize);

    QPainter painter;
    QLabel *spriteCanvas;
    int spriteCanvasSize;
    QPixmap *spritePixmap;

    void changePixmap(QPixmap newPixmap);

    void mousePress(QPoint globalMousePos);
    void mouseMove(QPoint globalMousePos);

    void mousePress(QPoint globalMousePos, bool isDraw);
    void mouseMove(QPoint globalMousePos, bool isDraw);

    void mouseRelease();

    void setPixelColor(QColor color);
    void clearCanvas();

    void changePixmap(QPixmap *newPixmap);

    void displayAnimationFrame(QPixmap *animationFramePixmap, bool actualSize);

signals:
    void updatePreviewUi();
    void startAction();
    void endAction();

private:
    QColor pixelColor;
    int spriteSize;

    // Used to make sure if the mouse is held down on the same pixel it doesnt set the pixel repeatedly without moving first.
    QPoint lastDrawnPixel;

    // Draws a pixel at a given position
    void drawPixel(QPoint pixelPosition);
    void erasePixel (QPoint pixelPoisiton);
    bool mouseOnSpriteCanvas(QPoint globalMousePos);
    QPoint getPixelPosition(QPoint mousePos);

    bool drawing;
};

#endif // SPRITECANVAS_H
