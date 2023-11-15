#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <Qpixmap>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

using std::vector;

class AnimationManager
{
public:
    AnimationManager(QScrollArea *framesPanel, int frameCount, int framesPerSecond, int spriteSize);
    int framesPerSecond;
    void setFrameCount(int newFrameCount);
    struct AnimationFrame
    {
        QLabel *uiElement;
        QPixmap animationPixmap;
        QPixmap framePreviewPixmap;
    };

    vector<AnimationFrame> animationFrames;

private:
    int frameCount;




    QScrollArea *framesPanel;
};

#endif // ANIMATIONMANAGER_H
