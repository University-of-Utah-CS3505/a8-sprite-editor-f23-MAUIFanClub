#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <QLabel>
#include <QScrollArea>
#include <QTimer>
#include <QVBoxLayout>
#include <Qpixmap>
#include "framepreviewui.h"
#include "spritecanvas.h"
#include "undoredomanager.h"

using std::vector;

class AnimationManager : public QObject
{
public:
    AnimationManager(SpriteCanvas *spriteCanvas,
                     QScrollArea *framesPanel,
                     int spriteSize,
                     bool createFirstFrame);

    struct AnimationFrame
    {
        FramePreviewUi *uiElement;
        QPixmap *animationPixmap;
    };

    vector<AnimationFrame> animationFrames;

    int framesPerSecond;

    void createNewFrame();
    void createNewFrame(QPixmap);
    void removeFrame();

    void undoAction();
    void redoAction();

    void clearAnimationFrames(int);

    QScrollArea *getFramesPanel();
signals:

public slots:
    void changeDisplayedFrame(int index);
    void updateFramePreviewElements();

    void startAction();
    void endAction();

private:
    QTimer updatePreviewTimer;

    int spriteSize;
    int currentFrameIndex;

    QScrollArea *framesPanel;

    SpriteCanvas *spriteCanvas;

    UndoRedoManager *undoRedoManager;
};

#endif // ANIMATIONMANAGER_H
