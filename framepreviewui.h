//Reviewed by: Noah Guidry
#ifndef FRAMEPREVIEWUI_H
#define FRAMEPREVIEWUI_H

#include <QLabel>
#include <QWidget>
#include <Qt>
//The UI object for the frame preview to work properly
class FramePreviewUi : public QLabel
{
    Q_OBJECT

public:
    //Gets the index of the frame, the parent widget to display the preview, and windows flags.
    explicit FramePreviewUi(int index,
                            QWidget *parent = Q_NULLPTR,
                            Qt::WindowFlags f = Qt::WindowFlags());
    //Destructor
    ~FramePreviewUi();

signals:
    //signal for if the preview gets clicked to switch to that frame
    void clicked(int index);

protected:
    //Handler for when the preview is clicked to display that frame
    void mousePressEvent(QMouseEvent *event);

private:
    //The index of the frame previe
    int index;
};

#endif // FRAMEPREVIEWUI_H
