#ifndef ANIMATIONPREVIEW_H
#define ANIMATIONPREVIEW_H

#include "animationmanager.h"
#include "spritecanvas.h"
#include <QObject>
#include <QThread>
#include <iostream>

class AnimationPreview : public QObject
{
    Q_OBJECT



public:
AnimationPreview(int frameRate, const std::vector<AnimationManager::AnimationFrame>& framesToAnimate, QObject* parent = nullptr);

 vector<AnimationManager::AnimationFrame> framesToAnimate;
 int i_frameRate;

public slots:
    void startPreview();
};

#endif // ANIMATIONPREVIEW_H
