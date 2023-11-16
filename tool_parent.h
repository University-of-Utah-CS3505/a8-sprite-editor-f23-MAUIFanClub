//Reviewed by: Joshua Daniels
#ifndef TOOL_PARENT_H
#define TOOL_PARENT_H
#include <QMouseEvent>
#include "spritecanvas.h"
//The parent that defines all the functions for tools
class Tool_Parent
{
public:
    Tool_Parent();
    //The generic method to use a tool
    virtual void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // TOOL_PARENT_H
