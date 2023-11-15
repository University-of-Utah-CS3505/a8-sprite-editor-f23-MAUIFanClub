#ifndef ERASETOOL_H
#define ERASETOOL_H
#include "tool_parent.h"

class eraseTool:public Tool_Parent
{
public:
    eraseTool();
    void useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown);
};

#endif // ERASETOOL_H
