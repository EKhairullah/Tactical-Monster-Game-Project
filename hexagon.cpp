#include "hexagon.h"


Hexagon::Hexagon()
{
    
}

void Hexagon::loadHexGrid(const QString& filePath, QGraphicsScene* scene, QGraphicsView *view)
{
    scene->clear();
    
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << filePath;
        return;
    }
    
    QTextStream in(&file);
    QStringList lines;
    while (!in.atEnd()) {
        lines << in.readLine();
    }
    file.close();
    
    for (int row = 0; row < lines.size()-1; row++) {
        const QString &line = lines[row];
        for (int col = 0; col < line.length()-1; ) {
            if (line[col] == '/') {
                QChar ch = line[col+1];
                if (ch == '\\' || ch == '_' || ch == '|') {
                    col += 2;
                    continue;
                }
                
                qreal x = (col / 6.0) * hexWidth * 1.5;
                qreal y = row * hexHeight * 0.5;
                createHexagon(x, y, ch, scene);
                col += 5;
            }
            else {
                col++;
            }
        }
    }
    
    if (!scene->items().empty()) {
        view->fitInView(scene->itemsBoundingRect().adjusted(-20, -20, 20, 20),
                        Qt::KeepAspectRatio);
    }
    // view->scale(6,6);
}
void Hexagon::createHexagon(qreal x, qreal y, QChar ch, QGraphicsScene *scene)
{
    QPolygonF hexagon;
    hexagon << QPointF(hexWidth*0.25, 0)
            << QPointF(hexWidth*0.75, 0)
            << QPointF(hexWidth, hexHeight*0.5)
            << QPointF(hexWidth*0.75, hexHeight)
            << QPointF(hexWidth*0.25, hexHeight)
            << QPointF(0, hexHeight*0.5);
    
    QGraphicsPolygonItem *hexItem = new QGraphicsPolygonItem(hexagon);
    hexItem->setPos(x, y);
    
    if (ch == '1') {
        hexItem->setBrush(QColor(100, 255, 100));
    } else if (ch == '2') {
        hexItem->setBrush(QColor(255, 255, 100));
    } else if (ch == '#') {
        hexItem->setBrush(QColor(100, 100, 255)); // Blue
    } else if (ch == '~') {
        hexItem->setBrush(QColor(255, 150, 200)); // Pink
    } else {
        hexItem->setBrush(Qt::white); // Empty
    }
    
    hexItem->setPen(QPen(Qt::black, 1));
    scene->addItem(hexItem);
}
