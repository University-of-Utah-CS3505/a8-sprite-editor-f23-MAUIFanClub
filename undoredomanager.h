#ifndef UNDOREDOMANAGER_H
#define UNDOREDOMANAGER_H

#include <QPixmap>
#include <stack>
#include <QPainter>
#include <QLabel>
#include "framepreviewui.h"

using std::vector;

class UndoRedoManager
{
public:
    UndoRedoManager();

    struct DrawAction
    {
        FramePreviewUi *framePreviewUi;
        QPixmap *framePixmapPtr;
        QPixmap newState;
        QPixmap previousState;
    };

    void startAction(QPixmap* framePixmapPtr, QPixmap oldPixmap);
    void endAction(QPixmap newPixmap);

    void undo();
    void redo();

    void removedFrameUpdateStacks(QPixmap *removedFrameQPixmapPtr);
private:
    std::stack<DrawAction> undoStack;
    std::stack<DrawAction> redoStack;

    DrawAction currentAction;
};

#endif // UNDOREDOMANAGER_H
