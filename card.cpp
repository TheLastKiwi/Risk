#include "card.h"
#include "QBitmap"
#include "mainwindow.h"
#include "handwindow.h"
Card::Card(QString im, HandWindow *parent, int armyID, QString countryName):QLabel(parent),image(im)
{
    setFixedSize(120,180);
    setPixmap(image);

    army = armyID;
    country = countryName;

}
Card::Card(Card *c, HandWindow *p):QLabel(p),image(c->image){
    setFixedSize(120,180);
    setPixmap(image);
    army = c->army;
    country =c->country;
}

void Card::select(){
    if(selected){
        move(this->x(),this->y()+30);
        selected = false;
    }
    else{
        move(this->x(),this->y()-30);
        selected = true;
    }
    //do something to show selected, different boarder or something
}

void Card::mousePressEvent(QMouseEvent *event){
    select();
}
