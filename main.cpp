#include "splash.h"
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString filePath = ":/grids/grid1.txt";
    splash w(filePath);
    // QString player1 = QInputDialog::getText(nullptr,"player1","Enter your player name:" );
    // QString player2 = QInputDialog::getText(nullptr, "Player2", "Enter your player name:");
    
    
    
    
    
    w.show();
    
    
    
    
    
    return a.exec();
}
