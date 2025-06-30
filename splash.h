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
QT_BEGIN_NAMESPACE
namespace Ui {
class splash;
}
QT_END_NAMESPACE

class splash : public QMainWindow
{
    Q_OBJECT

public:
    splash(QWidget *parent = nullptr);
    ~splash();
    
    
private slots:
    void goToNextTab();
    void goToGallery();
    void goToMainGamePage();
    void backToScreenPage();
    
    void on_SaveButton_clicked();
    
private:
    Ui::splash *ui;
};
#endif // SPLASH_H
