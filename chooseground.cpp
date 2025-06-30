#include "chooseground.h"

ChooseGround::ChooseGround(const QString &filePath):filePath(filePath){}

QList<HexCellData> ChooseGround::readData() {
    QList<HexCellData> data;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return data;
    
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        
        QStringList parts = line.split(" ");
        if (parts.size() >= 3) {
            int x = parts[0].toInt();
            int y = parts[1].toInt();
            QColor color(parts[2]);
            data.append({x, y, color});
        }
    }
    
    return data;
}

