//Reviewed by: Aidan Bott
#ifndef ANIMATIONPREVIEW_H
#define ANIMATIONPREVIEW_H

#include <QObject>
#include <QThread>
#include "spritecanvas.h"
#include "animationmanager.h"
#include <iostream>

//Holds all the data to allow the the preview to play effectivley
class AnimationPreview : public QObject
{
    Q_OBJECT

public:
    //Constructs and sets the items to allow the preview player to work properly
    AnimationPreview(
        const std::vector<AnimationManager::AnimationFrame> &framesToAnimate,
        QObject *parent = nullptr);
    //Contains all the frames that need to be animated
    vector<AnimationManager::AnimationFrame> framesToAnimate;
    //the index of the current frame
    int currentFrame;
    //Advances the frames to the next one or sets it to the 0 index if it is at the last index
    void advanceFrame();
    //The timer object
    QTimer *timer;
    //the aniamtion manager object taht helps the preview paly
    AnimationManager *tempManager;
    //Bool if the the preview should be played at its actual size
    bool actualSize;
    //bool if the preview is playing
    bool isPlaying = false;
public slots:
    //Reciever to see if the preview should be played
    void startPreview(AnimationManager*, bool allowingPlay);
    //Reciever to see if the preview should be stopped
    void stopPreview();
};

#endif // ANIMATIONPREVIEW_H
