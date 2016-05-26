#include "handwindow.h"
#include "ui_handwindow.h"
#include "card.h"
//#include "player.h"
HandWindow::HandWindow(Player *p, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandWindow)
{
    thePlayer = p;
    ui->setupUi(this);

}
void HandWindow::placeCard(Card *c, int i){
    c->move(10+120*i,30);
    //put card on screen
    //x offset is 70 * i or something that doesn't overlap
}

HandWindow::~HandWindow()
{
    delete ui;
}
void HandWindow::displayHand(){
    for(int i = 0; i < thePlayer->cardsInHand; i++){
        if(thePlayer->hand[i]){//if card not null
            placeCard(thePlayer->hand[i],i);
        }
    }
}

bool HandWindow::isSet(Card *c[3]){
    bool allSame = true;
    bool allDiff = true;
    if(!(c[0] && c[1] && c[2]))return false;

    if(c[0]->army == c[1]->army &&
            c[1]->army == c[2]->army){
        allSame = true;
    }
    else{
        allSame = false;
    }

    if(c[0]->army != c[1]->army &&
       c[0]->army != c[2]->army &&
            c[1]->army != c[2]->army){
        allDiff = true;
    }
    else{
        allDiff = false;
    }

    return allSame || allDiff;
}
