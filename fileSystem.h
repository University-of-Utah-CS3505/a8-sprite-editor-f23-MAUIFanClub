#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QObject>
#include <QFile>

class FileSystem : public QObject
{
public:
    FileSystem(){}
public slots:
    void loadJson(QString filepath);
    void saveSprite(QString filename);
signals:

private:

};

#endif // FILESYSTEM_H
