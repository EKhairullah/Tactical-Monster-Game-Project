#ifndef SPLASH_H
#define SPLASH_H
#include <QTabWidget>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QString>
#include <QPushButton>
#include <QDebug>
#include <QTabBar>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "hexagon.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class splash;
}
QT_END_NAMESPACE

class splash : public QMainWindow
{
    Q_OBJECT

public:
    
    explicit splash( const QString &gridFile, QWidget *parent = nullptr);
    ~splash();
    
    
private slots:
    void goToNextTab();
    void goToGallery();
    void goToMainGamePage();
    void backToScreenPage();
    

private:
    Ui::splash *ui;
    QGraphicsScene *scene;
    Hexagon hex;
    
};
#endif // SPLASH_H
