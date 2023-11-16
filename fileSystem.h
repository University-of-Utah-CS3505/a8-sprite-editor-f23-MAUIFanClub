#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QColor>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include "animationmanager.h"
#include "spritecanvas.h"

class FileSystem : public QObject
{
public:
    FileSystem();
    FileSystem(AnimationManager *, SpriteCanvas *);
    FileSystem &operator=(FileSystem other);

public slots:
    int loadJson(QString filepath);
    void saveSprite(QString filename, int size);
signals:

private:
    AnimationManager *animationManager;
    SpriteCanvas *spriteCanvas;
    void writeSpriteToJson(QJsonObject &sprite);
    int readSpritefromJson(const QJsonObject &sprite);
    void writeFrameToJson(QJsonObject &frame, QPixmap pixmap, int index);
};

#endif // FILESYSTEM_H
