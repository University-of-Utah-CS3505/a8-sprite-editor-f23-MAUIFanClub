#include "animationpreview.h"


AnimationPreview::AnimationPreview(
    const std::vector<AnimationManager::AnimationFrame> &framesToAnimate,
    QObject *parent)
    : QObject(parent)
    , framesToAnimate(framesToAnimate)
    , currentFrame(0)
{}

void AnimationPreview::startPreview(AnimationManager* animationManager, bool actualSize)
{
    isPlaying = true;
    this->actualSize = actualSize;
    currentFrame = 0;
    tempManager = animationManager;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this]() { advanceFrame(); });
    timer->start(1000/animationManager->framesPerSecond);

}
void AnimationPreview::stopPreview() {
    isPlaying = false;
    timer->stop();
    tempManager->changeDisplayedFrame(0);
}

void AnimationPreview::advanceFrame() {
    AnimationManager::AnimationFrame tempFrame;
    tempFrame = tempManager->animationFrames[currentFrame];



    tempManager->spriteCanvas->displayAnimationFrame(tempFrame.animationPixmap, actualSize);
    if(currentFrame == tempManager->animationFrames.size()-1) {
        currentFrame = 0;
    } else {
        currentFrame++;
    }
}

