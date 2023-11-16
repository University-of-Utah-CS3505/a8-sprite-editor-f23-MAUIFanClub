#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <Qpixmap>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QTimer>
#include "spritecanvas.h"
#include "framepreviewui.h"
#include "undoredomanager.h"

using std::vector;

class AnimationManager : public QObject
{
public:
    AnimationManager(SpriteCanvas *spriteCanvas, QScrollArea *framesPanel, int spriteSize);

    struct AnimationFrame
    {
        FramePreviewUi *uiElement;
        QPixmap *animationPixmap;
    };

    vector<AnimationFrame> animationFrames;

    int framesPerSecond;

    void createNewFrame();
    void removeFrame();

    void undoAction();
    void redoAction();

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
