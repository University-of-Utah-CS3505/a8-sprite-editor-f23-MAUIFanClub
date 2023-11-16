#include "painttool.h"

paintTool::paintTool()
{

}

void paintTool::useTool(QMouseEvent *event, SpriteCanvas* canvas, bool isHeldDown)
{
    Tool_Parent::useTool( event, canvas, isHeldDown);
    if(!isHeldDown)
    {
        canvas->paintFill(event->globalPosition().toPoint());
    }
}
