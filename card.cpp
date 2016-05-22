#include "card.h"
#include "QBitmap"
#include "mainwindow.h"
#include "handwindow.h"
Card::Card(QString im, HandWindow *parent,int cardNum, QString countryName):QLabel(parent),image(im)
{
    setFixedSize(71,96);
    setPixmap(image);

    army = cardNum % 3;
    country = countryName;

}
Card::Card(Card *c, HandWindow *p):QLabel(p),image(c->image){
    setFixedSize(71,96);
    setPixmap(image);
    army = c->army;
    country =c->country;

}

void Card::select(){
    //do something to show selected, different boarder or something
}
