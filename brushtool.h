#include "tool_parent.h"
#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H


class brushTool: public Tool_Parent
{
public:
    brushTool();
    void useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown);
};

#endif // BRUSHTOOL_H
