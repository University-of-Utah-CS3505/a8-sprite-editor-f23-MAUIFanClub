#ifndef PAINTTOOL_H
#define PAINTTOOL_H
#include "tool_parent.h"

class paintTool : public Tool_Parent
{
public:
    paintTool();
    void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // PAINTTOOL_H
