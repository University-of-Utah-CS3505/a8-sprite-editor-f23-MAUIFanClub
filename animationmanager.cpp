#include "animationmanager.h"
#include "framepreviewui.h"

AnimationManager::AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int frameCount, int framesPerSecond, int spriteSize)
{
    this->frameCount = frameCount;
    this->framesPerSecond = framesPerSecond;
    this->framesPanel = framesPanel;
    this->spriteCanvas = spriteCanvas;

    animationFrames = vector<AnimationFrame>(0);

    for (int i = 0; i < frameCount; i++)
    {
        AnimationFrame newFrame;

        QPixmap *animationPixmap = new QPixmap(spriteSize, spriteSize);
        animationPixmap->fill(Qt::lightGray);

        QPixmap framePreviewPixmap = animationPixmap->scaled(QSize(128,128));

        // Ui Frame Element Creation
        FramePreviewUi *frameUiElement = new FramePreviewUi(i);
        frameUiElement->setMinimumHeight(128);
        frameUiElement->setMaximumHeight(128);
        frameUiElement->setMinimumWidth(128);
        frameUiElement->setMaximumWidth(128);
        frameUiElement->setPixmap(framePreviewPixmap);

        QObject::connect(frameUiElement, &FramePreviewUi::clicked, this, &AnimationManager::changeDisplayedFrame);

        // Assignment of variables for newFrame
        newFrame.animationPixmap = animationPixmap;
        newFrame.framePreviewPixmap = framePreviewPixmap;
        newFrame.uiElement = frameUiElement;

        animationFrames.push_back(newFrame);

        this->framesPanel->widget()->layout()->addWidget(frameUiElement);
    }

    changeDisplayedFrame(0);
}

void AnimationManager::setFrameCount(int newFrameCount)
{
    animationFrames.resize(newFrameCount);
}

void AnimationManager::changeDisplayedFrame(int index)
{
    spriteCanvas->changePixmap(animationFrames[index].animationPixmap);
}

int AnimationManager::getSize()
{
    return animationFrames.size();
}
