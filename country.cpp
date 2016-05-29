#include "country.h"
#include "QBitmap"
#include "game.h"
#include "QMouseEvent"
#include "iostream"
#include "game.h"
Country::Country(QString im, QString sel, QString p1, QString p2, MainWindow *parent, QString n, Game *g):QLabel(parent),image(im),name(n),theGame(g)
{

    setFixedSize(230,190);
    this->P1 = p1;
    this->P2= p2;
    this->Sel = sel;
    setPixmap(im);
    //    QBitmap q();
    QPixmap d(im);

    setMask(d.mask());
    //setScaledContents(true);

}
void Country::mousePressEvent(QMouseEvent* event)
{
    //TO TEST IF CONNECTIONS MADE
    //    for(int i = 0; i < neighborCounter; i++){
    //        if (neighbors[i]->isVisible()){
    //            neighbors[i]->hide();
    //        }
    //        else{
    //            neighbors[i]->show();
    //        }
    //    }
    //    offset=event->localPos().toPoint();
    //TO TEST IF CONNECTIONS MADE
    //TEST DICE SHOW
    //    int attacker[3];
    //    int defender[2];
    //    for(int i = 0; i < 3; i++){
    //        attacker[i] = qrand() % 6;
    //    }
    //    for(int i = 0; i < 2; i++){
    //        defender[i] = qrand() % 6;
    //    }
    //    Attack *a = new Attack(0,0);
    //    int q=qrand()%3+1,w=qrand()%2+1;
    //    a->sort(attacker,q,defender,w);
    //    theGame->showDice(attacker,q,defender,w);
    //TEST DICE SHOW

    switch(theGame->currentPhase){
    case Game::bonusPhase:
        //place armies on countries
        if (controller == theGame->currentPlayer){//must be controller
            numArmies++;

            theGame->currentPlayer->freeArmies--;
            theGame->updateBonusArmiesLabel();
            if(theGame->currentPlayer->freeArmies == 0){

                if(theGame->isIntro){//if intro then switch players
                    theGame->setupNextPlayer();

                    if(theGame->currentPlayer->playerID==0){
                        //went to next player, now if it's palyer 0 just go to main game
                        theGame->nextPhase();
                        theGame->isIntro = false;
                        return;
                    }
                    theGame->getBonusArmies();
                    //theGame->currentPlayer->freeArmies = theGame->getBonusArmies();
                }
                else{ //if not intro then just go to next phase
                    theGame->nextPhase();
                }
            }
        }

        //numArmies++;
        break;
    case Game::attackPhase:
        if(theGame->from == this){
            select(false);
            theGame->from=0;return;
        }
        if (!theGame->from){ //nothing in from so first click
            if (controller == theGame->currentPlayer){ // first coutry must be controlled by the player
                theGame->setCountry(this);
            }
            //else do nothing because the first target can't be another player
        }
        else{
            if (controller != theGame->currentPlayer){ //second country must not be controlled by current player
                if(theGame->from->isNeighbor(this)){//check if viable target
                    theGame->setCountry(this);
                    Attack *a= new Attack(theGame->from,theGame->to);
                    a->attack(3,2);
                   theGame->to=0;theGame->from=0;
                    ////TODO
                    //probably want to do a window here to ask how many dice to roll
                }
            }
            //else not same player so do nothing
        }
        break;
    case Game::reinforcePhase:
        if(theGame->from == this){
            select(false);
            theGame->from=0;return;
        }
        if (!theGame->from){ //nothing in from so first click
            if (controller == theGame->currentPlayer){ // first coutry must be controlled by the player
                theGame->setCountry(this);
            }
            //else do nothing because the first target can't be another player
        }
        else{
            if (controller == theGame->currentPlayer){ //in reinforce phase armies move between 2 adjacent countries controlled by the same player
                if(theGame->from->isNeighbor(this)){//check if viable target
                    theGame->setCountry(this);
                    Reinforce *r= new Reinforce(theGame->from,theGame->to);
                    r->move(2);
                    theGame->to=0;theGame->from=0;
                    ////TODO

                    //probably want to do a window here to ask how many to move
                }
            }
            //else not same player so do nothing
        }
        break;
    case Game::endPhase:
        //not sure about this one
        break;
    case Game::startPhase:
        if(controller == 0){
            theGame->giveControlStart(this);
            //move(100,200);
            //setText(QString(numArmies));
            if(theGame->occupiedTerritories == 42) theGame->nextPhase();
        }
        break;
    }

}
void Country::addNeighbor(Country *c){
    if(isNeighbor(c)) return;
    neighbors[neighborCounter++] = c;
    c->addNeighbor(this);
}

bool Country::isNeighbor(Country *c){
    if (c == 0) return false;
    for(int i = 0; i < neighborCounter; i++){
        if (neighbors[i] == c) return true;
    }
    return false;
}
void Country::select(bool sel){
    if(sel){
        setPixmap(this->Sel);
        selected = true;
    }
    else{
        setControllerImage();
        selected=false;
    }
    //change boarder to show selected
}
void Country::setControllerImage(){
    if (controller->playerID==0){
        setPixmap(P1);
    }
    else{
        setPixmap(P2);
    }
}
void Country::setController(Player *p){
    controller = p;
    setControllerImage();
    //do the thing that shows they own the country
}

void Country::mouseMoveEvent(QMouseEvent *ev){

    //move(ev->windowPos().x() - offset.x(),ev->windowPos().y() - offset.y());
}

void Country::mouseReleaseEvent(QMouseEvent *ev){

    std::cout << "Owner: " <<&*controller <<" #Occupied: " << theGame->occupiedTerritories <<" Phase: " << theGame->currentPhase <<
                 " currentPlayer: " <<theGame->currentPlayer->playerID << " Armies: " <<numArmies <<" FreeArmies: " << theGame->currentPlayer->freeArmies
              <<std::endl;
}
