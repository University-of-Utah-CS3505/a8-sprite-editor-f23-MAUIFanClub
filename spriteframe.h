#ifndef SPRITEFRAME_H
#define SPRITEFRAME_H

#include <QPixmap>

class SpriteFrame
{
public:
    SpriteFrame(int spriteSize);
    ~SpriteFrame();

    QPixmap *spriteCanvas;
};

#endif // SPRITEFRAME_H
