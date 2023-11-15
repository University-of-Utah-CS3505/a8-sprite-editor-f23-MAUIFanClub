#include "fileSystem.h"
void FileSystem::loadJson(QString filepath)
{
    //QFile loadFile(filepath);

}

void FileSystem::saveSprite(QString filename)
{
    QFile saveFile(filename);
    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Could not open save file.");
        return;
    }

    QJsonObject JsonSprite;
    writeSpriteToJson(JsonSprite);

}

void FileSystem::writeSpriteToJson(QJsonObject &sprite)
{
    sprite["size"] = 4;//TODO
    sprite["numFrames"] = 1; //TODO
}
