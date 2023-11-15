#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QColor>
#include "animationmanager.h"
#include "spritecanvas.h"

class FileSystem : public QObject
{
public:
    FileSystem();
    FileSystem(AnimationManager*, SpriteCanvas*);

public slots:
    void loadJson(QString filepath);
    void saveSprite(QString filename, int size);
signals:

private:
    AnimationManager* am;
    SpriteCanvas* sc;
    void writeSpriteToJson(QJsonObject &sprite);
    void readSpritefromJson(QJsonObject &sprite);
    void writeFrameToJson(QJsonObject &frame, QPixmap pixmap, int index);
};

#endif // FILESYSTEM_H