#include "animationpreview.h"

AnimationPreview::AnimationPreview(
    int frameRate,
    const std::vector<AnimationManager::AnimationFrame> &framesToAnimate,
    QObject *parent)
    : QObject(parent)
    , i_frameRate(frameRate)
    , framesToAnimate(framesToAnimate)
{}

void AnimationPreview::startPreview()
{
    AnimationManager::AnimationFrame tempFrame;

    for (int i = 0; i < framesToAnimate.size(); i++) {
        tempFrame = framesToAnimate[i];

        // Call function to display given frame
        //SpriteCanvas::changePixmap(tempFrame.animationPixmap);
        //
        QThread::sleep(1000 / i_frameRate);
    }
    std::cout << "Start Preview Entered";
}
