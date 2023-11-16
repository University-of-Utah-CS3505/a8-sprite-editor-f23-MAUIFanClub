//Reviewed by: Noah Guidry
#include "undoredomanager.h"

UndoRedoManager::UndoRedoManager() {}

void UndoRedoManager::startAction(QPixmap *framePixmapPtr, QPixmap oldPixmap)
{
    // Clears redoStack if it contains actions
    if (!redoStack.empty())
        redoStack = std::stack<DrawAction>();

    currentAction.framePixmapPtr = framePixmapPtr;
    currentAction.previousState = oldPixmap.copy();
}

void UndoRedoManager::endAction(QPixmap newPixmap)
{
    currentAction.newState = newPixmap.copy();

    undoStack.push(currentAction);
    currentAction = {};
}

void UndoRedoManager::undo()
{
    if (undoStack.empty())
        return;

    // Gets current undo action
    DrawAction undoAction = undoStack.top();

    *undoAction.framePixmapPtr = undoAction.previousState;

    // Removes from undoStack and adds to redoStack
    undoStack.pop();
    redoStack.push(undoAction);
}

void UndoRedoManager::redo()
{
    if (redoStack.empty())
        return;

    // Gets current redo action
    DrawAction redoAction = redoStack.top();

    *redoAction.framePixmapPtr = redoAction.newState;

    // Removes from redoStack and adds to undoStack
    redoStack.pop();
    undoStack.push(redoAction);
}

void UndoRedoManager::removedFrameUpdateStacks(QPixmap *removedFrameQPixmapPtr)
{
    vector<DrawAction> storedUndoActions;

    // Loops over each stack to find draw actions that contain the removed frame data.
    // If an draw action is not the removed frame it adds that draw action to a vector to be pushed back.
    while (!undoStack.empty()) {
        DrawAction undoAction = undoStack.top();
        undoStack.pop();

        if (undoAction.framePixmapPtr != removedFrameQPixmapPtr) {
            storedUndoActions.push_back(undoAction);
        }
    }

    undoStack = std::stack<DrawAction>();
    redoStack = std::stack<DrawAction>();

    // Adds draw actions that were stored back to their stacks.
    for (int i = storedUndoActions.size() - 1; i >= 0; i--) {
        undoStack.push(storedUndoActions[i]);
    }
}
