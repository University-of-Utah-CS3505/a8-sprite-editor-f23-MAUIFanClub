//Reviewed by: Drew Fenter
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
    //Creats a new frame for the sprite
    void createNewFrame();
    //Creates a new frame from a given pixmap, used for loading
    void createNewFrame(QPixmap);
    //removes a frame from the sprite
    void removeFrame();
    //Calls the undoredo manager to undo the last action
    void undoAction();
    //Calls the undoredo manager to redo the last action
    void redoAction();
    //Clears all the frames in the sprite, needs a sprite size
    void clearAnimationFrames(int);
    //Holds the sprite canvas object to create frames frome
    SpriteCanvas *spriteCanvas;

signals:

public slots:
    //Changes the displayed frame to the frame at the index
    void changeDisplayedFrame(int index);
    //Updates the preivew frame in the frames slot after a frame has been changed
    void updateFramePreviewElements();
    //Starts an action for the undo redo manager to capture
    void startAction();
    //ends an action for the undo redo manager to capture
    void endAction();

private:
    //The current Height and width of the sprite
    int spriteSize;
    //the current index of the current selected frame
    int currentFrameIndex;
    //The area where the frame previews are held
    QScrollArea *framesPanel;
    //The manager that handles all the undo and redo requests
    UndoRedoManager *undoRedoManager;
};

#endif // ANIMATIONMANAGER_H
