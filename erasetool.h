#ifndef ERASETOOL_H
#define ERASETOOL_H
#include "tool_parent.h"

class EraseTool : public Tool_Parent
{
public:
    EraseTool();
    void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // ERASETOOL_H
