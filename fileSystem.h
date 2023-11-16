#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "animationmanager.h"
#include "spritecanvas.h"
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>

class FileSystem : public QObject
{
public:
    FileSystem();
    FileSystem(AnimationManager*, SpriteCanvas*);
    FileSystem& operator= (FileSystem other);

public slots:
    int loadJson(QString filepath);
    void saveSprite(QString filename, int size);
signals:

private:
    AnimationManager* animationManager;
    SpriteCanvas* spriteCanvas;
    void writeSpriteToJson(QJsonObject &sprite);
    int readSpritefromJson(const QJsonObject &sprite);
    void writeFrameToJson(QJsonObject &frame, QPixmap pixmap, int index);
};

#endif // FILESYSTEM_H
