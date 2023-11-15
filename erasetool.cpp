#include "erasetool.h"

eraseTool::eraseTool()
{

}

void eraseTool::useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown)
{
    Tool_Parent::useTool( event, canvas, isHeldDown);
    if(isHeldDown)
    {
        canvas->mouseMove(event->globalPosition().toPoint(), false);
    }
    else
    {
        canvas->mousePress(event->globalPosition().toPoint(), false);
    }
}
