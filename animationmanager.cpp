#include "animationmanager.h"

AnimationManager::AnimationManager(QScrollArea *framesPanel, int frameCount, int framesPerSecond, int spriteSize)
{
    this->frameCount = frameCount;
    this->framesPerSecond = framesPerSecond;
    this->framesPanel = framesPanel;

    animationFrames = vector<AnimationFrame>(0);

    for (int i = 0; i < frameCount; i++)
    {
        AnimationFrame newFrame;

        QPixmap animationPixmap(spriteSize, spriteSize);
        animationPixmap.fill(Qt::lightGray);

        QPixmap framePreviewPixmap = animationPixmap.scaled(QSize(128,128));

        // Ui Frame Element Creation
        QLabel *frameUiElement = new QLabel();
        frameUiElement->setMinimumHeight(128);
        frameUiElement->setMaximumHeight(128);
        frameUiElement->setMinimumWidth(128);
        frameUiElement->setMaximumWidth(128);
        frameUiElement->setPixmap(framePreviewPixmap);

        // Assignment of variables for newFrame
        newFrame.animationPixmap = animationPixmap;
        newFrame.framePreviewPixmap = framePreviewPixmap;
        newFrame.uiElement = frameUiElement;

        animationFrames.push_back(newFrame);

        this->framesPanel->widget()->layout()->addWidget(frameUiElement);
    }
}

void AnimationManager::setFrameCount(int newFrameCount)
{
    animationFrames.resize(newFrameCount);
}
