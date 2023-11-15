#include "fileSystem.h"

FileSystem::FileSystem(AnimationManager* animManager, SpriteCanvas* spriteCanv)
{
    am = animManager;
    sc = spriteCanv;
}
void FileSystem::loadJson(QString filepath)
{
    QFile loadFile(filepath);

}
void FileSystem::readSpritefromJson(QJsonObject &sprite)
{

}

void FileSystem::saveSprite(QString filename, int size)
{
    QFile saveFile(filename);
    if(!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning("Could not open save file.");
        return;
    }

    QJsonObject JsonSprite;
    JsonSprite["size"] = size;
    writeSpriteToJson(JsonSprite);
    QJsonDocument JsonDoc(JsonSprite);
    saveFile.write(JsonDoc.toJson());
}

void FileSystem::writeSpriteToJson(QJsonObject &sprite)
{
    sprite["numFrames"] = am->getSize();
    QJsonArray frames;

    int frameIndex = 0;
    foreach(AnimationManager::AnimationFrame frame, am->animationFrames){
        QJsonObject frameObject;
        writeFrameToJson(frameObject, *frame.animationPixmap, frameIndex);
        frames.append(frameObject);
        frameIndex++;
    }

    sprite["frames"] = frames;
}
void FileSystem::writeFrameToJson(QJsonObject &frame, QPixmap pixmap, int index)
{
    QJsonArray pixels;
    QImage image = pixmap.toImage();

    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            QColor color(image.pixel(x, y));

            QJsonObject pixelInfo;
            pixelInfo["x"] = x;
            pixelInfo["y"] = y;
            pixelInfo["red"] = color.red();
            pixelInfo["green"] = color.green();
            pixelInfo["blue"] = color.blue();
            pixelInfo["alpha"] = color.alpha();

            pixels.append(pixelInfo);
        }
    }

    frame[QStringLiteral("frame").append(QString::number(index))] = pixels;
}
