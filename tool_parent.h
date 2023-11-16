#ifndef TOOL_PARENT_H
#define TOOL_PARENT_H
#include <QMouseEvent>
#include "spritecanvas.h"
class Tool_Parent
{
public:
	Tool_Parent();
	/// \brief useTool preforms the action associated with this tool
	/// \param event - contains data describing a mouse action
	/// \param canvas - the sprite canvas to draw onto
	/// \param isHeldDown - represents wether or not the right mouse is held
	virtual void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // TOOL_PARENT_H
