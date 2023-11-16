//Reviewed by: Aidan Bott
#include "tool_parent.h"
#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H
//The brush tool for general drawing
class BrushTool : public Tool_Parent
{
public:
    BrushTool();
    //The use tool method do draw onto the canvas
    void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // BRUSHTOOL_H
