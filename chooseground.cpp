// HexFileReader.cpp
#include "chooseground.h"
#include <QFile>
#include <QTextStream>

HexFileReader::HexFileReader(const QString &path) : filePath(path) {}

QList<HexCellData> HexFileReader::read() {
    QList<HexCellData> result;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        
        qDebug() <<"file not fuound!!!\n";
        return result;
    }
    qDebug() <<"file fuound my love!!!\n";
    QTextStream in(&file);
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains("/")) {
            int col = 0;
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == '/' && i + 2 < line.length() && line[i+2] == '\\') {
                    QChar symbol = line[i+1];
                    if (symbol != ' ' && symbol != '_') {
                        result.append({row, col, symbol});
                    }
                    ++col;
                }
            }
            ++row;
        }
    }
    
    return result;
}
