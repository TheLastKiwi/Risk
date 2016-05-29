#include "handwindow.h"
#include "ui_handwindow.h"
#include "card.h"
#include <iostream>
#include "errordialog.h"
#include "game.h"
HandWindow::HandWindow(Player *p, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HandWindow)
{
    thePlayer = p;
    ui->setupUi(this);


}
//void HandWindow::placeCard(Card *c, int i){
//    c->move(10+120*i,30);
//    //put card on screen
//    //x offset is 70 * i or something that doesn't overlap
//}

HandWindow::~HandWindow()
{
    delete ui;
}
void HandWindow::displayHand(){
//    for(int i = 0; i < thePlayer->cardsInHand;i++){
//        thePlayer->hand[i] = new Card(thePlayer->hand[i],this);
//    }
    for(int i = 0; i < thePlayer->cardsInHand; i++){
//        if(thePlayer->hand[i]){//if card not null
//            placeCard(thePlayer->hand[i],i);
//        }
        if(thePlayer->hand[i]->selected)thePlayer->hand[i]->select();
        thePlayer->hand[i]->move(10+120*i,40);
        thePlayer->hand[i]->show();

        std::cout << thePlayer->hand[i]->x() << " " << thePlayer->hand[i]->y() << " "<< thePlayer->hand[i]->parent() <<std::endl;
    }
    ui->lblNextValue->setText(QString("Next set is worth: ") + QString::number(thePlayer->theGame->turnInValue[thePlayer->theGame->turnInNumber]) + QString(" bonus armies"));
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
int HandWindow::getBonusTurninAmount(){
    int bonus =0;
    Game *g = thePlayer->theGame;
    for(int i = 0; i < 3; i++){
        if(g->map.value(selectedHand[i]->country)->controller == thePlayer)bonus+=2;
    }
    bonus+= g->turnInValue[g->turnInNumber++];
}

void HandWindow::on_btnTurnIn_clicked()
{
    ErrorDialog *e;
    if(thePlayer != thePlayer->theGame->currentPlayer){
        e = new ErrorDialog(QString("You can only turn in cards on your turn"));
        e->show();
        return;
    }
    if(countSelectedCards()==3){
        setSelectedHand();
        if(isSet(selectedHand)){
            thePlayer->freeArmies += getBonusTurninAmount();
            thePlayer->theGame->updateBonusArmiesLabel();

            int n =0;
            Card *newHand[5] = {0,0,0,0,0};
            for(int i = 0; i < thePlayer->cardsInHand;i++){
                if(!thePlayer->hand[i]->selected){
                    newHand[n++] = thePlayer->hand[i];
                }
            }
            thePlayer->updateHand(newHand);
            displayHand();
            thePlayer->theGame->turnInNumber++;
        }
        else{
            e = new ErrorDialog(QString("The cards must all be of differnt armies,\n or all of the same army"));
            e->show();
        }
    }
    else{

        e = new ErrorDialog(QString("You must select exactly 3 cards"));


        e->show();

    }
    //if is set then add x to bonus
    //if not bonus phase then you can't turn them in


}


void HandWindow::on_btnClose_clicked()
{
    close();
}
