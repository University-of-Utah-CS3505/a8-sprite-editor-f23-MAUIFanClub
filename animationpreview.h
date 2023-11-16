#ifndef ANIMATIONPREVIEW_H
#define ANIMATIONPREVIEW_H

#include <QObject>
#include <QThread>
#include "spritecanvas.h"
#include "animationmanager.h"
#include <iostream>

class AnimationPreview : public QObject
{
    Q_OBJECT

public:
    AnimationPreview(
        const std::vector<AnimationManager::AnimationFrame> &framesToAnimate,
        QObject *parent = nullptr);

    vector<AnimationManager::AnimationFrame> framesToAnimate;
    int currentFrame;
    void advanceFrame();
    QTimer *timer;
    bool actualSize;
    AnimationManager* tempManager;
public slots:
    void startPreview(AnimationManager*, bool allowingPlay);
    void stopPreview();
};

#endif // ANIMATIONPREVIEW_H
