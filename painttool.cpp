//Reviewed by: Ahmed Abdalla
#include "painttool.h"

paintTool::paintTool() {}

void paintTool::useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown)
{
    QPoint mouseLocalPos = canvas->spriteCanvas->mapFromGlobal(event->globalPosition()).toPoint();

    Tool_Parent::useTool(event, canvas, isHeldDown);
    if (!isHeldDown && canvas->mouseOnSpriteCanvas(mouseLocalPos)) {
        canvas->paintFill(event->globalPosition().toPoint());
    }
}
