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
    void goToSelectionMap();
    
    void onMapSelected(const QString &path);
    
    void on_pushButton_clicked();
    
    
    void on_label_7_linkHovered(const QString &link);
    
private:
    Ui::splash *ui;
    QGraphicsScene *scene1,*scene2,*scene3,*scene4,*scene5, *scene6, *scene7, *scene8;
    Hexagon hex;
    QString selectedMapPath;
    int chooseMap;

    
    
};
#endif // SPLASH_H
