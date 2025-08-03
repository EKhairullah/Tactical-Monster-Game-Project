#ifndef CLICKABLEMAPITEM_H
#define CLICKABLEMAPITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QGraphicsRectItem>

class ClickableMapItem: public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ClickableMapItem(const QString &mapPath);
    
    
signals:
    void mapClicked(QString &path);
    
protected:
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    
private:
    QString mapPath;
    
};

#endif // CLICKABLEMAPITEM_H
