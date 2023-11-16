#ifndef UNDOREDOMANAGER_H
#define UNDOREDOMANAGER_H

#include <QDebug>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include "framepreviewui.h"
#include <stack>
using std::vector;

class UndoRedoManager
{
public:
	UndoRedoManager();
	/// \brief The DrawAction struct establishes the valid types of
	struct DrawAction
	{
		FramePreviewUi *framePreviewUi;
		QPixmap *framePixmapPtr;
		QPixmap newState;
		QPixmap previousState;
	};
	/// \brief startAction marks the start of a penstroke, updating the redo stack
	/// \param framePixmapPtr - the current state of the pixMap
	/// \param oldPixmap - the previous state of the pixMap
	void startAction(QPixmap *framePixmapPtr, QPixmap oldPixmap);
	/// \brief endAction marks the end of a penstroke, updating the undo stack
	/// \param framePixmapPtr - the current state of the pixMap
	/// \param oldPixmap - the previous state of the pixMap
	void endAction(QPixmap newPixmap);

	/// \brief undo reverts the most recent change made
	void undo();
	/// \brief redo reverts the most undo action
	void redo();
	/// \brief removedFrameUpdateStacks clears the frame update stacks of any data from removed frames
	/// \param removedFrameQPixmapPtr the recently removed frame
	void removedFrameUpdateStacks(QPixmap *removedFrameQPixmapPtr);

private:
	/// \brief undoStack contains the states of the canvas before each recent edit
	std::stack<DrawAction> undoStack;
	/// \brief redoStack contains the states of the canvas before each recent undo
	std::stack<DrawAction> redoStack;
	/// \brief currentAction is the drawAction that has taken place most recently
	DrawAction currentAction;
};

#endif // UNDOREDOMANAGER_H
