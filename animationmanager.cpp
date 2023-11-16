//Reviewed by: Drew Fenter
#include "animationmanager.h"

AnimationManager::AnimationManager(SpriteCanvas *spriteCanvas,
                                   QScrollArea *framesPanel,
                                   int spriteSize,
                                   bool createFirstFrame)
    : framesPanel(framesPanel)
    , spriteSize(spriteSize)
    , spriteCanvas(spriteCanvas)
    , framesPerSecond(30)
{
    undoRedoManager = new UndoRedoManager();

    currentFrameIndex = 0;
    framesPanel->widget()->layout()->setAlignment(Qt::AlignHCenter);

    animationFrames = vector<AnimationFrame>(0);
    if (createFirstFrame) {
        createNewFrame();
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
    frameUiElement->setPixmap(animationPixmap->scaled(QSize(128, 128)));

    QObject::connect(frameUiElement,
                     &FramePreviewUi::clicked,
                     this,
                     &AnimationManager::changeDisplayedFrame);

    frameUiElement->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Assignment of variables for newFrame
    newFrame.animationPixmap = animationPixmap;
    newFrame.uiElement = frameUiElement;

    animationFrames.push_back(newFrame);

    framesPanel->widget()->layout()->addWidget(frameUiElement);
    changeDisplayedFrame(animationFrames.size()-1);
}

void AnimationManager::createNewFrame(QPixmap map)
{
    AnimationFrame newFrame;

    int index = animationFrames.size();

    QPixmap *animationPixmap = new QPixmap(spriteSize, spriteSize);
    *animationPixmap = map.copy();

    // Ui Frame Element Creation
    FramePreviewUi *frameUiElement = new FramePreviewUi(index);
    frameUiElement->setMinimumHeight(128);
    frameUiElement->setMaximumHeight(128);
    frameUiElement->setMinimumWidth(128);
    frameUiElement->setMaximumWidth(128);
    frameUiElement->setPixmap(animationPixmap->scaled(QSize(128, 128)));

    QObject::connect(frameUiElement,
                     &FramePreviewUi::clicked,
                     this,
                     &AnimationManager::changeDisplayedFrame);

    frameUiElement->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // Assignment of variables for newFrame
    newFrame.animationPixmap = animationPixmap;
    newFrame.uiElement = frameUiElement;

    animationFrames.push_back(newFrame);

    framesPanel->widget()->layout()->addWidget(frameUiElement);
    changeDisplayedFrame(animationFrames.size()-1);
}

void AnimationManager::removeFrame()
{
    if (animationFrames.size() == 1)
        return;

    undoRedoManager->removedFrameUpdateStacks(animationFrames.back().animationPixmap);

    int removedFrameIndex = animationFrames.size() - 1;

    AnimationFrame *af = &animationFrames[removedFrameIndex];

    if (currentFrameIndex == removedFrameIndex)
        changeDisplayedFrame(--currentFrameIndex);

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();
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
    for (int i = 0; i < animationFrames.size(); i++) {
        animationFrames[i].uiElement->setPixmap(
            animationFrames[i].animationPixmap->scaled(QSize(128, 128)));
    }
}

void AnimationManager::startAction()
{
    undoRedoManager->startAction(animationFrames[currentFrameIndex].animationPixmap,
                                 *animationFrames[currentFrameIndex].animationPixmap);
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

void AnimationManager::clearAnimationFrames(int size)
{
    spriteSize = size;
    for (int i = 0; i < animationFrames.size(); i++) {
        removeFrame();
    }
    AnimationFrame *af = &animationFrames[animationFrames.size() - 1];

    framesPanel->widget()->layout()->removeWidget(af->uiElement);
    delete af->uiElement;

    animationFrames.pop_back();
    delete undoRedoManager;
    undoRedoManager = new UndoRedoManager();
}
