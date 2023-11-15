#include "animationpreview.h"
#include "spritecanvas.h"
#include <iostream>
#include <QThread>


AnimationPreview::AnimationPreview(int frameRate, vector<AnimationManager::AnimationFrame> framesToAnimate, QObject *parent)  : i_frameRate(frameRate), QObject(parent) , framesToAnimate(framesToAnimate)
{
    this->i_frameRate = frameRate;
}

void AnimationPreview::startPreview() {


   AnimationManager::AnimationFrame tempFrame;

   for(int i = 0; i < framesToAnimate.size(); i++) {
       tempFrame = framesToAnimate[i];

       // Call function to display given frame
       QThread::sleep(1000/i_frameRate);

       SpriteCanvas::changePixmap(tempFrame);


   }
    std:: cout << "Start Preview Entered" ;

}

