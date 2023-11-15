#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <Qpixmap>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QTimer>
#include "spritecanvas.h"
#include "framepreviewui.h"

using std::vector;

class AnimationManager : public QObject
{
public:
    AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int spriteSize);

    void setFrameCount(int newFrameCount);

    struct AnimationFrame
    {
        FramePreviewUi *uiElement;
        QPixmap *animationPixmap;
    };

    vector<AnimationFrame> animationFrames;

    void createNewFrame();
    void removeFrame();

signals:

public slots:
    void changeDisplayedFrame(int index);

private:
    QTimer updatePreviewTimer;

    int spriteSize;

    QScrollArea *framesPanel;

    SpriteCanvas *spriteCanvas;
};

#endif // ANIMATIONMANAGER_H
