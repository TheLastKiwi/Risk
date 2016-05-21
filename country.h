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
    Country(QString im, MainWindow *parent, QString n, Game *g);
    const QString image;
    const QString name;

    Game *theGame;
    //TEMP DEBUG VARIABLES
    QPoint offset;
    //TEMP DEBUG VARIABLES
    Player *controller = NULL;
    int numArmies = 0;

    Country *neighbors[6];
    int neighborCounter = 0;

    void addNeighbor(Country *c){
        if(isNeighbor(c)) return;
        neighbors[neighborCounter++] = c;
        c->addNeighbor(this);
    }

    bool isNeighbor(Country *c){
        if (c == 0) return false;
        for(int i = 0; i < neighborCounter; i++){
            if (neighbors[i] == c) return true;
        }
        return false;
    }
    ~Country(){}
protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // COUNTRY_H
