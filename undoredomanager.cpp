#include "undoredomanager.h"
#include <QDebug>

UndoRedoManager::UndoRedoManager() { }

void UndoRedoManager::StartAction(QPixmap oldPixmap)
{
    // Clears redoStack if it contains actions
    if (!redoStack.empty()) redoStack = std::stack<DrawAction>();

    currentAction.previousState = oldPixmap.copy();
}

void UndoRedoManager::EndAction(QPixmap newPixmap)
{
    currentAction.newState = newPixmap.copy();

    undoStack.push(currentAction);
    currentAction = {};
}

void UndoRedoManager::Undo(QPainter *painter, QLabel *spriteLabel, QPixmap *spritePixMap, int paintLabelSize)
{
    if (undoStack.empty()) return;

    painter->end();

    // Gets current undo action
    DrawAction undoAction = undoStack.top();

    // Copies previous state pixMap to the main pixMap
    *spritePixMap = undoAction.previousState.copy();

    painter->begin(spritePixMap);

    // Updates spriteLabel pixMap
    spriteLabel->setPixmap(spritePixMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));

    // Removes from undoStack and adds to redoStack
    undoStack.pop();
    redoStack.push(undoAction);
}

void UndoRedoManager::Redo(QPainter *painter, QLabel *spriteLabel, QPixmap *spritePixMap, int paintLabelSize)
{
    if (redoStack.empty()) return;

    painter->end();

    // Gets current redo action
    DrawAction redoAction = redoStack.top();

    // Copies new state pixMap to the main pixMap
    *spritePixMap = redoAction.newState.copy();

    painter->begin(spritePixMap);

    // Updates spriteLabel pixMap
    spriteLabel->setPixmap(spritePixMap->scaled(paintLabelSize, paintLabelSize, Qt::KeepAspectRatio, Qt::FastTransformation));

    // Removes from redoStack and adds to undoStack
    redoStack.pop();
    undoStack.push(redoAction);
}

