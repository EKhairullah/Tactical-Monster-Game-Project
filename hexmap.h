#ifndef HEXMAP_H
#define HEXMAP_H
#include "hexagon.h"
#include <QFile>

class HexMap {
private:
    QVector<Hexagon> hexagons;
    qreal hexWidth, hexHeight;
    QGraphicsScene *scene;
    
public:
    HexMap(qreal hexWidth, qreal hexHeight, QGraphicsScene *scene);
    void readFromFile(const QString &filePath);
    void render();
};


#endif // HEXMAP_H
