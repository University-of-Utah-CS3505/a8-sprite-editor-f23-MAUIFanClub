#ifndef TOOL_PARENT_H
#define TOOL_PARENT_H
#include <QMouseEvent>
#include "spritecanvas.h"
class Tool_Parent
{
public:
    Tool_Parent();
    virtual void useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown);
};

#endif // TOOL_PARENT_H
