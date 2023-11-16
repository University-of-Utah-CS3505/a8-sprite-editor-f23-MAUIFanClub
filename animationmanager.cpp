#include "animationmanager.h"

AnimationManager::AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int spriteSize, bool createFirstFrame) : framesPanel(framesPanel), spriteSize(spriteSize)
{
    this->spriteCanvas = spriteCanvas;

    animationFrames = vector<AnimationFrame>(0);
    if(createFirstFrame)
    {
        createNewFrame();

    changeDisplayedFrame(0);
    }
}


void AnimationManager::createNewFrame()
{
    AnimationFrame newFrame;

    int index = animationFrames.size();

    QPixmap *animationPixmap = new QPixmap(spriteSize, spriteSize);
    animationPixmap->fill(Qt::lightGray);

    // Ui Frame Element Creation
    FramePreviewUi *frameUiElement = new FramePreviewUi(index);
    frameUiElement->setMinimumHeight(128);
    frameUiElement->setMaximumHeight(128);
    frameUiElement->setMinimumWidth(128);
    frameUiElement->setMaximumWidth(128);
    frameUiElement->setPixmap(animationPixmap->scaled(QSize(128,128)));

    QObject::connect(frameUiElement, &FramePreviewUi::clicked, this, &AnimationManager::changeDisplayedFrame);

    // Assignment of variables for newFrame
    newFrame.animationPixmap = animationPixmap;
    newFrame.uiElement = frameUiElement;

    animationFrames.push_back(newFrame);

    framesPanel->widget()->layout()->addWidget(frameUiElement);
}

void AnimationManager::createNewFrame(QPixmap map)
{
    AnimationFrame newFrame;

    int index = animationFrames.size();

    QPixmap *animationPixmap = new QPixmap(spriteSize, spriteSize);
    *animationPixmap= map.copy();

    // Ui Frame Element Creation
    FramePreviewUi *frameUiElement = new FramePreviewUi(index);
    frameUiElement->setMinimumHeight(128);
    frameUiElement->setMaximumHeight(128);
    frameUiElement->setMinimumWidth(128);
    frameUiElement->setMaximumWidth(128);
    frameUiElement->setPixmap(animationPixmap->scaled(QSize(128,128)));

    QObject::connect(frameUiElement, &FramePreviewUi::clicked, this, &AnimationManager::changeDisplayedFrame);

    // Assignment of variables for newFrame
    newFrame.animationPixmap = animationPixmap;
    newFrame.uiElement = frameUiElement;

    animationFrames.push_back(newFrame);

    framesPanel->widget()->layout()->addWidget(frameUiElement);
}

void AnimationManager::removeFrame()
{
    if (animationFrames.size() == 1) return;

    AnimationFrame *af = &animationFrames[animationFrames.size()-1];

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();

    changeDisplayedFrame(animationFrames.size()-1);
}

void AnimationManager::changeDisplayedFrame(int index)
{
    spriteCanvas->previewFrameUi = animationFrames[index].uiElement;
    spriteCanvas->changePixmap(animationFrames[index].animationPixmap);
}

int AnimationManager::getSize()
{
    return animationFrames.size();
}

QScrollArea *AnimationManager::getFramesPanel()
{
    return framesPanel;
}
void AnimationManager::clearAnimationFrames()
{
    for(int i = 0; i < animationFrames.size(); i++)
    {
        removeFrame();

    }
    AnimationFrame *af = &animationFrames[animationFrames.size()-1];

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();
}
