//Reviewed by: Aidan Bott
#ifndef ERASETOOL_H
#define ERASETOOL_H
#include "tool_parent.h"
//The erase tool for general erasing
class EraseTool : public Tool_Parent
{
public:
    EraseTool();
    //The use tool to erase from the current canvas
    void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // ERASETOOL_H
