#ifndef ANIMATIONPREVIEW_H
#define ANIMATIONPREVIEW_H
#include "animationmanager.h"
#include <QObject>

class AnimationPreview : public QObject
{
    Q_OBJECT



public:
AnimationPreview(QObject *parent = nullptr);
 vector<AnimationManager::AnimationFrame> framesToAnimate;
 int i_frameRate;
 explicit AnimationPreview(int frameRate, vector<AnimationManager::AnimationFrame> framesToAnimate, QObject *parent = nullptr);


public slots:
    void startPreview();
};

#endif // ANIMATIONPREVIEW_H
