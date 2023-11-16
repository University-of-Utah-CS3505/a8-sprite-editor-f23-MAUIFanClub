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

//Manages all the frames of the sprite and gives functionality to und and redo and load.
class AnimationManager : public QObject
{
public:
    //Takes in all the necessary data to build frames for the sprite
    AnimationManager(SpriteCanvas *spriteCanvas,
                     QScrollArea *framesPanel,
                     int spriteSize,
                     bool createFirstFrame);
    //Holds data for frames including the pix map and the actual UI element
    struct AnimationFrame
    {
        FramePreviewUi *uiElement;
        QPixmap *animationPixmap;
    };
    //Contains all the frames of the sprite
    vector<AnimationFrame> animationFrames;
    //The rate of speed of the playback
    int framesPerSecond = 1;

    void createNewFrame();
    void createNewFrame(QPixmap);
    void removeFrame();

    void undoAction();
    void redoAction();

    void clearAnimationFrames(int);

    SpriteCanvas *spriteCanvas;


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



    UndoRedoManager *undoRedoManager;
};

#endif // ANIMATIONMANAGER_H
