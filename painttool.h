//Reviewed by: Ahmed Abdalla
#ifndef PAINTTOOL_H
#define PAINTTOOL_H
#include "tool_parent.h"
//The paint tool for filling in sections of a frame based on if the pixels around the selected pixel are the same color
class paintTool : public Tool_Parent
{
public:
    paintTool();
    //the method to paint in a section of the paint
    void useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown);
};

#endif // PAINTTOOL_H
