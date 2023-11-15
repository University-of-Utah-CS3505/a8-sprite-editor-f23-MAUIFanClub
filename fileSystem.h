#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class FileSystem : public QObject
{
public:
    FileSystem(){}
public slots:
    void loadJson(QString filepath);
    void saveSprite(QString filename);
signals:

private:
    void writeSpriteToJson(QJsonObject &sprite);
    void readSpritefromJson(QJsonObject &sprite);
};

#endif // FILESYSTEM_H
