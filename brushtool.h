#include "tool_parent.h"
#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H


class BrushTool: public Tool_Parent
{
public:
    BrushTool();
    void useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown);
};

#endif // BRUSHTOOL_H
