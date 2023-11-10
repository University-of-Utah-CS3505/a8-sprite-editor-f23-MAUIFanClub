#ifndef UNDOREDOMANAGER_H
#define UNDOREDOMANAGER_H

#include <QPixmap>
#include <stack>
#include <QPainter>
#include <QLabel>

class UndoRedoManager
{
public:
    UndoRedoManager();

    struct DrawAction
    {
        QPixmap newState;
        QPixmap previousState;
    };

    void StartAction(QPixmap oldPixmap);
    void EndAction(QPixmap newPixmap);

    void undo(QPainter *painter, QLabel *spriteLabel, QPixmap *spritePixMap, int paintLabelSize);
    void redo(QPainter *painter, QLabel *spriteLabel, QPixmap *spritePixMap, int paintLabelSize);
private:
    std::stack<DrawAction> undoStack;
    std::stack<DrawAction> redoStack;

    DrawAction currentAction;
};

#endif // UNDOREDOMANAGER_H
