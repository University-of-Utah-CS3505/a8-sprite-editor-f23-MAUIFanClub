#include "animationmanager.h"

AnimationManager::AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int spriteSize, bool createFirstFrame) : framesPanel(framesPanel), spriteSize(spriteSize), spriteCanvas(spriteCanvas)
{
    undoRedoManager = new UndoRedoManager();

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
    animationPixmap->fill(Qt::color0);

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

    undoRedoManager->removedFrameUpdateStacks(animationFrames.back().animationPixmap);

    AnimationFrame *af = &animationFrames[animationFrames.size()-1];

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();

    changeDisplayedFrame(animationFrames.size()-1);
}

void AnimationManager::changeDisplayedFrame(int index)
{
    animationFrames[currentFrameIndex].uiElement->setStyleSheet("");

    currentFrameIndex = index;
    spriteCanvas->changePixmap(animationFrames[index].animationPixmap);

    animationFrames[currentFrameIndex].uiElement->setStyleSheet("QFrame {border: 10px solid;}");
}

void AnimationManager::updateFramePreviewElements()
{
    for (int i = 0; i < animationFrames.size(); i++)
    {
        animationFrames[i].uiElement->setPixmap(animationFrames[i].animationPixmap->scaled(QSize(128,128)));
    }
}

void AnimationManager::startAction()
{
    undoRedoManager->startAction(animationFrames[currentFrameIndex].animationPixmap, *animationFrames[currentFrameIndex].animationPixmap);
}

void AnimationManager::endAction()
{
    undoRedoManager->endAction(*animationFrames[currentFrameIndex].animationPixmap);
}

void AnimationManager::undoAction()
{
    spriteCanvas->painter.end();

    undoRedoManager->undo();
    updateFramePreviewElements();

    spriteCanvas->changePixmap(animationFrames[currentFrameIndex].animationPixmap);
}

void AnimationManager::redoAction()
{
    spriteCanvas->painter.end();

    undoRedoManager->redo();
    updateFramePreviewElements();

    spriteCanvas->changePixmap(animationFrames[currentFrameIndex].animationPixmap);
}

QScrollArea *AnimationManager::getFramesPanel()
{
    return framesPanel;
}
void AnimationManager::clearAnimationFrames(int size)
{
    spriteSize = size;
    for(int i = 0; i < animationFrames.size(); i++)
    {
        removeFrame();

    }
    AnimationFrame *af = &animationFrames[animationFrames.size()-1];

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();
    delete undoRedoManager;
    undoRedoManager = new UndoRedoManager();
}
