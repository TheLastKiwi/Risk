#ifndef COUNTRY_H
#define COUNTRY_H
#include "QLabel"
#include "player.h"
#include "mainwindow.h"
#include "string.h"

//TEMP INCLUDE
#include "QPoint"
class Country : public QLabel
{

public:
    Country(QString im, QString sel, QString p1, QString p2, MainWindow *parent, QString n, Game *g);
    const QString image;
    QString P1,P2,Sel;
    const QString name;

    Game *theGame;
    //TEMP DEBUG VARIABLES
    //QPoint offset;
    //TEMP DEBUG VARIABLES
    void setController(Player *p);
    Player *controller = NULL;
    int numArmies = 0;
    bool selected;
    void select(bool sel);
    Country *neighbors[6];
    int neighborCounter = 0;
    void addNeighbor(Country *c);
    bool isNeighbor(Country *c);
    void setControllerImage();


    ~Country(){}
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // COUNTRY_H
