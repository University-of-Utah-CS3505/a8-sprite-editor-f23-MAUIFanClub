//Reviewed by: Drew Fenter
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
//Contains all the methods and utility to save and load sprites into the editor
class FileSystem : public QObject
{
public:
    //creates a generic filesystem only for loading
    FileSystem();
    //Creates a filesystem with an animation manager and a sprite canvas to help the file system load and save.
    FileSystem(AnimationManager *, SpriteCanvas *);
    //Destructor
    ~FileSystem();
    //Sets the current filesystem to the other filesystem
    FileSystem &operator=(FileSystem other);

public slots:
    //A reciever to load a sprite from a filepath
    int loadJson(QString filepath);
    //A reciever to save a sprite to a filepath with the sprite size
    void saveSprite(QString filename, int size);
signals:

private:
    //The animation manager holder
    AnimationManager *animationManager;
    //The sprite canvas holder
    SpriteCanvas *spriteCanvas;
    //Helper method for saving, writes a sprite to Json
    void writeSpriteToJson(QJsonObject &sprite);
    //Helper method for saving, writes a frame to Json
    void writeFrameToJson(QJsonObject &frame, QPixmap pixmap, int index);
    //A helper method for loading, reads all sprite data from a Json object. Returns the sprite size.
    int readSpritefromJson(const QJsonObject &sprite);

};

#endif // FILESYSTEM_H
