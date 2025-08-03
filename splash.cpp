#include "splash.h"
#include "./ui_splash.h"
#include <QTabWidget>
#include <QWidget>
#include <QGraphicsView>
#include "hexagon.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QIntValidator>

splash::splash( const QString &filePath, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::splash)
    , scene1(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->tabWidget->findChild<QTabBar *>()->hide();
    
    ui->tabWidget->setCurrentIndex(0);
    connect(ui->startButton, &QPushButton::clicked, this, &splash::goToNextTab);
    qDebug() << "Start Button Clicked\n";
    connect(ui->GalleryButton,&QPushButton::clicked, this, &splash::goToGallery);
    qDebug() <<"Gallery Button Clicked\n";
    connect(ui->MainPageButton, &QPushButton::clicked, this, &splash::goToSelectionMap);
    qDebug() << "main page's button clicked\n";
    connect(ui->BackButton, &QPushButton::clicked, this, &splash::backToScreenPage);
    qDebug() << "Back Button clicked\n";
    
    ///Draw the hexagon
    
    
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene); // فرض بر این که در UI یک GraphicsView داری
    QStringList Paths= {":/grids/grid1.txt",":/grids/grid2.txt",":/grids/grid3.txt",
                         ":/grids/grid4.txt",":/grids/grid5.txt",":/grids/grid6.txt"
                          ,":/grids/grid7.txt",":/grids/grid8.txt"
    };
    ///////**************************************************************for selecting the map macanism\\
    /// 
    ///
    chooseMap = ui->chooseMap_2->text().toInt();
    qDebug()<<ui->chooseMap_2->text().toInt();
    
    qDebug()<<"the number of the map is: "<<chooseMap<<"\n";
    hex.loadHexGrid(Paths[ui->chooseMap_2->text().toInt()],scene,ui->graphicsView);
    
    // good style for Buttons
    ////////////////////////////////////////////////
    /// 
    /// 
    ui->startButton->setStyleSheet(R"(QPushButton {
    background-color: #2ecc71;       
    color: white;
    border: 2px solid #a3f9b3;         
    border-radius: 12px;
    padding: 10px 25px;
    font-size: 16px;
    font-weight: 600;
    font-family: "Segoe UI", "IRANSans", sans-serif;
    box-shadow: 0px 0px 10px #00ffae; 
}

QPushButton:hover {
    background-color: #27ae60;
    border: 2px solid #76ffb4;
    box-shadow: 0px 0px 15px #00ffae;
    transform: scale(1.03);
}

QPushButton:pressed {
    background-color: #1e8449;
    border: 2px solid #49e697;
    box-shadow: none;
    padding-left: 26px;
    padding-top: 11px;
}

QPushButton:disabled {
    background-color: #7f8c8d;
    border: 2px solid #bdc3c7;
    color: #ecf0f1;
}
)");
    //////////////////////////////////////////////////////
    
    ui->GalleryButton->setStyleSheet(R"(QPushButton {
    background-color: #2ecc71;       
    color: white;
    border: 2px solid #a3f9b3;       
    border-radius: 12px;
    padding: 10px 25px;
    font-size: 16px;
    font-weight: 600;
    font-family: "Segoe UI", "IRANSans", sans-serif;
    box-shadow: 0px 0px 10px #00ffae; 
}

QPushButton:hover {
    background-color: #27ae60;
    border: 2px solid #76ffb4;
    box-shadow: 0px 0px 15px #00ffae;
    transform: scale(1.03);
}

QPushButton:pressed {
    background-color: #1e8449;
    border: 2px solid #49e697;
    box-shadow: none;
    padding-left: 26px;
    padding-top: 11px;
}

QPushButton:disabled {
    background-color: #7f8c8d;
    border: 2px solid #bdc3c7;
    color: #ecf0f1;
}
)");
    
    /////////////////////////////////////////////////
    ui->MainPageButton->setStyleSheet(R"(QPushButton {
    background-color: #2ecc71;     
    color: white;
    border: 2px solid #a3f9b3;  
    border-radius: 12px;
    padding: 10px 25px;
    font-size: 16px;
    font-weight: 600;
    font-family: "Segoe UI", "IRANSans", sans-serif;
    box-shadow: 0px 0px 10px #00ffae; 
}

QPushButton:hover {
    background-color: #27ae60;
    border: 2px solid #76ffb4;
    box-shadow: 0px 0px 15px #00ffae;
    transform: scale(1.03);
}

QPushButton:pressed {
    background-color: #1e8449;
    border: 2px solid #49e697;
    box-shadow: none;
    padding-left: 26px;
    padding-top: 11px;
}

QPushButton:disabled {
    background-color: #7f8c8d;
    border: 2px solid #bdc3c7;
    color: #ecf0f1;
}
)");

    
    ui->BackButton->setStyleSheet(R"(QPushButton {
    background-color: #2ecc71;       
    color: white;
    border: 2px solid #a3f9b3;      
    border-radius: 12px;
    padding: 10px 25px;
    font-size: 16px;
    font-weight: 600;
    font-family: "Segoe UI", "IRANSans", sans-serif;
    box-shadow: 0px 0px 10px #00ffae; 
}

QPushButton:hover {
    background-color: #27ae60;
    border: 2px solid #76ffb4;
    box-shadow: 0px 0px 15px #00ffae;
    transform: scale(1.03);
}

QPushButton:pressed {
    background-color: #1e8449;
    border: 2px solid #49e697;
    box-shadow: none;
    padding-left: 26px;
    padding-top: 11px;
}

QPushButton:disabled {
    background-color: #7f8c8d;
    border: 2px solid #bdc3c7;
    color: #ecf0f1;
}
)");
    //set Agent Pictures
    
    QPixmap pixmap1(":/Agents/Billy.webp");
    ui->pic1->setPixmap(pixmap1.scaled(ui->pic1->size()));
    ui->pic1->setScaledContents(true);
    
    QPixmap pixmap2(":/Agents/Reketon.webp");
    ui->pic2->setPixmap(pixmap2.scaled(ui->pic2->size()));
    ui->pic2->setScaledContents(true);
    
    
    QPixmap pixmap3(":/Agents/Angus.webp");
    ui->pic3->setPixmap(pixmap3.scaled(ui->pic3->size()));
    ui->pic3->setScaledContents(true);
    
    
    QPixmap pixmap4(":/Agents/Duraham.webp");
    ui->pic4->setPixmap(pixmap4.scaled(ui->pic4->size()));
    ui->pic4->setScaledContents(true);
    
    QPixmap pixmap5(":/Agents/Reketon.webp");
    ui->pic5->setPixmap(pixmap5.scaled(ui->pic5->size()));
    ui->pic5->setScaledContents(true);
    
    QPixmap pixmap6(":/Agents/Medusa.webp");
    ui->pic6->setPixmap(pixmap6.scaled(ui->pic6->size()));
    ui->pic6->setScaledContents(true);
    
    QPixmap pixmap7(":/Agents/Bunka.webp");
    ui->pic7->setPixmap(pixmap7.scaled(ui->pic7->size()));
    ui->pic7->setScaledContents(true);
    
    QPixmap pixmap8(":/Agents/Sanka.webp");
    ui->pic8->setPixmap(pixmap8.scaled(ui->pic8->size()));
    ui->pic8->setScaledContents(true);
    
    QPixmap pixmap9(":/Agents/Lamorak.webp");
    ui->pic9->setPixmap(pixmap9.scaled(ui->pic9->size()));
    ui->pic9->setScaledContents(true);
    
    QPixmap pixmap10(":/Agents/Kabu.webp");
    ui->pic10->setPixmap(pixmap10.scaled(ui->pic10->size()));
    ui->pic10->setScaledContents(true);
    
    QPixmap pixmap11(":/Agents/Rajakal.webp");
    ui->pic11->setPixmap(pixmap11.scaled(ui->pic11->size()));
    ui->pic11->setScaledContents(true);
    
    QPixmap pixmap12(":/Agents/Salih.webp");
    ui->pic12->setPixmap(pixmap12.scaled(ui->pic12->size()));
    ui->pic12->setScaledContents(true);
    
    QPixmap pixmap13(":/Agents/Khan.webp");
    ui->pic13->setPixmap(pixmap13.scaled(ui->pic13->size()));
    ui->pic13->setScaledContents(true);
    
    QPixmap pixmap14(":/Agents/Eloi.webp");
    ui->pic14->setPixmap(pixmap14.scaled(ui->pic14->size()));
    ui->pic14->setScaledContents(true);
    
    QPixmap pixmap15(":/Agents/Boi.webp");
    ui->pic15->setPixmap(pixmap15.scaled(ui->pic15->size()));
    ui->pic15->setScaledContents(true);
    
    QPixmap pixmap16(":/Agents/Kanar.webp");
    ui->pic16->setPixmap(pixmap16.scaled(ui->pic16->size()));
    ui->pic16->setScaledContents(true);
    
    QPixmap pixmap17(":/Agents/Elsa.webp");
    ui->pic17->setPixmap(pixmap17.scaled(ui->pic17->size()));
    ui->pic17->setScaledContents(true);
    
    QPixmap pixmap18(":/Agents/Karissa.webp");
    ui->pic18->setPixmap(pixmap18.scaled(ui->pic18->size()));
    ui->pic18->setScaledContents(true);
    
    QPixmap pixmap19(":/Agents/Sir philiph.webp");
    ui->pic19->setPixmap(pixmap19.scaled(ui->pic19->size()));
    ui->pic19->setScaledContents(true);
    
    QPixmap pixmap20(":/Agents/Frost.webp");
    ui->pic20->setPixmap(pixmap20.scaled(ui->pic20->size()));
    ui->pic20->setScaledContents(true);
    
    QPixmap pixmap21(":/Agents/Reketon.webp");
    ui->pic21->setPixmap(pixmap21.scaled(ui->pic21->size()));
    ui->pic21->setScaledContents(true);
    
    QPixmap pixmap22(":/Agents/Tusk.webp");
    ui->pic22->setPixmap(pixmap22.scaled(ui->pic22->size()));
    ui->pic22->setScaledContents(true);
    
    QPixmap pixmap23(":/Agents/Rambo.webp");
    ui->pic23->setPixmap(pixmap23.scaled(ui->pic23->size()));
    ui->pic23->setScaledContents(true);
    
    QPixmap pixmap24(":/Agents/Sabrina.webp");
    ui->pic24->setPixmap(pixmap24.scaled(ui->pic24->size()));
    ui->pic24->setScaledContents(true);
    
    

}


splash::~splash()
{
    delete ui;
}

void splash::goToNextTab()
{
    // ui->tabWidget->setTabEnabled(0,false);
    ui->tabWidget->setCurrentIndex(1);
    QWidget *tab2 = ui->tabWidget->widget(1);
    
    tab2->setStyleSheet("background-image: url(:/pictures/8.jpg);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-attachment: fixed;"
                        "background-color: transparent;");

}

void splash::goToGallery()
{
    ui->tabWidget->setCurrentIndex(2);
    QWidget *GalleryTab = ui->tabWidget->widget(2);
    
    GalleryTab->setStyleSheet("background-image: url(:/pictures/11.jpg);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-attachment: fixed;"
                        "background-color: transparent;");
    
}

void splash::goToMainGamePage()
{
    
    hex.loadHexGrid(":/grids/grid1.txt",scene1,ui->graphicsView);
    qDebug() << "Go to the map selection\n";
    // selectedMap.clear();
    ui->tabWidget->setCurrentIndex(1);
    
    
    QString player1,player2;
    do{
        player1 = QInputDialog::getText(nullptr,"Player1","Enter your first player name: ");
        if(player1.isEmpty())
        {
            QMessageBox::warning(this,"Warning","Player1 can not be empty!");
        }
        
        
    }while(player1.isEmpty());
    
    do{
        player2 = QInputDialog::getText(nullptr,"Player2", "Enter your second player name: ");
        if(player2.isEmpty())
        {
            QMessageBox::warning(this,"Warning", "Player2 can not be empty!");
        }
        
    }while(player2.isEmpty());
    
    
    //mecanism for open the map

    
    
    ui->lineEditPlayer1->setText(player1);
    ui->lineEditPlayer2->setText(player2);
    
    ui->lineEditPlayer1->setReadOnly(true);
    ui->lineEditPlayer2->setReadOnly(true);
    
    ui->tabWidget->setCurrentIndex(3);
    QWidget *tab2 = ui->tabWidget->widget(3);
    
    tab2->setStyleSheet("background-image: url(:/pictures/1.jpg);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-attachment: fixed;"
                        "background-color: transparent;");
}

void splash::backToScreenPage()
{
    ui->tabWidget->setCurrentIndex(1);
}

void splash::goToSelectionMap()
{
    ui->tabWidget->setCurrentIndex(4);
    QString path1 = ":/grids/grid1.txt";
    QString path2 = ":/grids/grid2.txt";
    QString path3 = ":/grids/grid3.txt";
    QString path4 = ":/grids/grid4.txt";
    QString path5 = ":/grids/grid5.txt";
    QString path6 = ":/grids/grid3.txt";
    QString path7 = ":/grids/grid4.txt";
    QString path8 = ":/grids/grid5.txt";
    Hexagon h;
    qDebug() << "the object of the Hexagon created\n";
    scene1 = new QGraphicsScene(this);
    scene2 = new QGraphicsScene(this);
    scene3 = new QGraphicsScene(this);
    scene4 = new QGraphicsScene(this);
    scene5 = new QGraphicsScene(this);
    scene6 = new QGraphicsScene(this);
    scene7 = new QGraphicsScene(this);
    scene8 = new QGraphicsScene(this);
    ui->map1->setScene(scene1);
    ui->map2->setScene(scene2);
    ui->map3->setScene(scene3);
    ui->map4->setScene(scene4);
    ui->map5->setScene(scene5);
    ui->map6->setScene(scene6);
    ui->map7->setScene(scene7);
    ui->map8->setScene(scene8);
    
    h.loadHexGrid(path1,scene1, ui->map1);
    h.loadHexGrid(path2,scene2, ui->map2);
    h.loadHexGrid(path3,scene3, ui->map3);
    h.loadHexGrid(path4,scene4, ui->map4);
    h.loadHexGrid(path5,scene5,ui->map5);
    h.loadHexGrid(path6,scene6, ui->map6);
    h.loadHexGrid(path7,scene7, ui->map7);
    h.loadHexGrid(path8,scene8,ui->map8);
    qDebug() <<"loadHexGrid called with path"<<path1;
    qDebug() <<"\nloadHexGrid called with path"<<path2;
    qDebug() <<"\nloadHexGrid called with path"<<path3;
    


    
}







void splash::on_pushButton_clicked()
{
    QIntValidator *valid = new QIntValidator(1,9,this);
    ui->chooseMap_2->setValidator(valid);
    
    //connect to the map
    connect(ui->chooseMap_2, &QLineEdit::returnPressed, this, [=]() {
        int number = ui->chooseMap_2->text().toInt();
        QMessageBox::information(this, "Enter the number of map ", QString("you entered %1 map").arg(number));
    });
     
    qDebug()<<ui->chooseMap_2->text().toInt()<<"chooseMap";
    
    qDebug()<<"the number of map is:\n";
    chooseMap = ui->chooseMap_2->text().toInt();;
    goToMainGamePage();
                                      
}


