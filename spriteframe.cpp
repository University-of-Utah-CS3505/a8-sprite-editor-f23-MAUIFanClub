#include "spriteframe.h"

SpriteFrame::SpriteFrame(int spriteSize)
{
    spriteCanvas = new QPixmap(spriteSize, spriteSize);
}

SpriteFrame::~SpriteFrame()
{
    delete spriteCanvas;
}
