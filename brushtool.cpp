//Reviewed by: Aidan Bott
#include "brushtool.h"

BrushTool::BrushTool() {}
void BrushTool::useTool(QMouseEvent *event, SpriteCanvas *canvas, bool isHeldDown)
{
    Tool_Parent::useTool(event, canvas, isHeldDown);
    if (isHeldDown) {
        canvas->mouseMove(event->globalPosition().toPoint(), true);
    } else {
        canvas->mousePress(event->globalPosition().toPoint(), true);
    }
}
