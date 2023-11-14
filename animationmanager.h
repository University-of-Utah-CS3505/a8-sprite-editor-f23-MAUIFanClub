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

    void setFrameCount(int newFrameCount);
private:
    int frameCount;
    int framesPerSecond;

    struct AnimationFrame
    {
        QLabel *uiElement;
        QPixmap animationPixmap;
        QPixmap framePreviewPixmap;
    };

    vector<AnimationFrame> animationFrames;

    QScrollArea *framesPanel;
};

#endif // ANIMATIONMANAGER_H
