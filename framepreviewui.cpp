#include "framepreviewui.h"

FramePreviewUi::FramePreviewUi(int index, QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    this->index = index;
}

FramePreviewUi::~FramePreviewUi() {}

void FramePreviewUi::mousePressEvent(QMouseEvent *event)
{
    emit clicked(index);
}
