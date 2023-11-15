#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <Qpixmap>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include "spritecanvas.h"

using std::vector;

class AnimationManager
{
public:
    AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int frameCount, int framesPerSecond, int spriteSize);

    void setFrameCount(int newFrameCount);

    struct AnimationFrame
    {
        QLabel *uiElement;
        QPixmap *animationPixmap;
        QPixmap framePreviewPixmap;
    };

    vector<AnimationFrame> animationFrames;
    int getSize();
signals:

public slots:
    void changeDisplayedFrame(int index);

private:
    int frameCount;
    int framesPerSecond;

    QScrollArea *framesPanel;

    SpriteCanvas *spriteCanvas;
};

#endif // ANIMATIONMANAGER_H
