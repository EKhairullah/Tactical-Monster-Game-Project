#ifndef CHOOSEGROUND_H
#define CHOOSEGROUND_H
#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QList>
#include <QColor>

struct HexCellData {
    int x;
    int y;
    QColor color;
};


class ChooseGround
{
public:
    ChooseGround(const QString &filePath);
    QList<HexCellData> readData();
    
    
private:
    QString filePath;
    
};

#endif // CHOOSEGROUND_H
