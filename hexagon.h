#ifndef HEXAGON_H
#define HEXAGON_H
#include <QString>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QChar>
#include <QDebug>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QFile>

class Hexagon
{ 
  
public:
    
    Hexagon();
    void loadHexGrid(const QString& filePath, QGraphicsScene* scene, QGraphicsView *view);
    void createHexagon(qreal x, qreal y, QChar ch, QGraphicsScene *scene);
    
private:
    const qreal hexSize = 45.0;
    const qreal hexWidth = hexSize * 2;
    const qreal hexHeight = hexSize * qSqrt(3);
    
    QGraphicsScene *scene1, *scene2, *scene3, *scene4, *scene5,
        *scene6, *scene7, *scene8, *scene9;
    
    
};

#endif // HEXAGON_H
