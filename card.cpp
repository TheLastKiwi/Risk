#include "card.h"
#include "QBitmap"
#include "mainwindow.h"
#include "handwindow.h"
Card::Card(QString im, QWidget *parent, int armyID, QString countryName):QLabel(parent),image(im)
{
    setFixedSize(120,180);
    setPixmap(image);

    army = armyID;
    country = countryName;
    selected = false;

}
Card::Card(Card *c, QWidget *parent):QLabel(parent),image(c->image){
    this->setFixedSize(120,180);
    this->setPixmap(c->image);
    this->army = c->army;
    this->country =c->country;
    this->selected = false;
}

void Card::select(){
//    move(this->x(),this->y()+30);
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
