//Reviewed by: George Guo
#ifndef SPRITECANVAS_H
#define SPRITECANVAS_H

#include <QColor>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QPointF>

using std::vector;

class SpriteCanvas : public QObject
{
    Q_OBJECT
public:
    SpriteCanvas(QLabel *spriteCanvas, int spriteSize);

    QPainter painter;
    QLabel *spriteCanvas;
    int spriteCanvasSize;
    QPixmap *spritePixmap;

    bool canDraw;

    void changePixmap(QPixmap newPixmap);

    void mousePress(QPoint globalMousePos);
    void mouseMove(QPoint globalMousePos);

    void mousePress(QPoint globalMousePos, bool isDraw);
    void mouseMove(QPoint globalMousePos, bool isDraw);

    void mouseRelease();

    void setPixelColor(QColor color);
    void clearCanvas();

    void changePixmap(QPixmap *newPixmap);

    void paintFill(QPoint globalMousePos);

    void displayAnimationFrame(QPixmap *animationFramePixmap, bool actualSize);
    void refreshSpriteCanvas(QLabel *spriteCanvas, int spriteSize);

    bool mouseOnSpriteCanvas(QPoint globalMousePos);

    QLabel *getSpriteCanvas();

signals:
    void updatePreviewUi();
    void startAction();
    void endAction();

    void undoAction();
    void redoAction();

private:
    QColor pixelColor;
    int spriteSize;

    // Used to make sure if the mouse is held down on the same pixel it doesnt set the pixel repeatedly without moving first.
    QPoint lastDrawnPixel;

    // Draws a pixel at a given position
    void drawPixel(QPoint pixelPosition);
    void erasePixel(QPoint pixelPoisiton);
    QPoint getPixelPosition(QPoint mousePos);

    void findAllPaintFillPixels(vector<QPoint> *paintFillPixels,
                                QPoint currentPixelPos,
                                QImage spriteImg,
                                QColor clickedPixelColor);

    bool drawing;
};

#endif // SPRITECANVAS_H
