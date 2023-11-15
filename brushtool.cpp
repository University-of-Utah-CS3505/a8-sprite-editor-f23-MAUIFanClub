#include "brushtool.h"

brushTool::brushTool()
{

}
void brushTool::useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown)
{
    Tool_Parent::useTool( event, canvas, isHeldDown);
    if(isHeldDown)
    {
        canvas->mouseMove(event->globalPosition().toPoint(), true);
    }
    else
    {
        canvas->mousePress(event->globalPosition().toPoint(), true);
    }

}
