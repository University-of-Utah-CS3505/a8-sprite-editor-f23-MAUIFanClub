#ifndef FRAMEPREVIEWUI_H
#define FRAMEPREVIEWUI_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class FramePreviewUi : public QLabel
{
    Q_OBJECT

public:
    explicit FramePreviewUi(int index,
                            QWidget *parent = Q_NULLPTR,
                            Qt::WindowFlags f = Qt::WindowFlags());
    ~FramePreviewUi();

signals:
    void clicked(int index);

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    int index;
};

#endif // FRAMEPREVIEWUI_H
