#include "clickablemapitem.h"
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QGraphicsPathItem>



ClickableMapItem::ClickableMapItem(const QString &mapPath): mapPath(mapPath)
{
    setAcceptedMouseButtons(Qt::LeftButton);
    setFlag(QGraphicsItem::ItemIsSelectable); // اختیاری برای انتخاب‌شدن
    
    
}

void ClickableMapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
     qDebug() << "ClickableMapItem clicked! Path:" << mapPath;
    emit mapClicked(mapPath);
    
}


