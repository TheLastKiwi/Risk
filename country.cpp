#include "country.h"
#include "QBitmap"
#include "game.h"
#include "QMouseEvent"
#include "iostream"
#include "game.h"
Country::Country(QString im, MainWindow *parent, QString n, Game *g):QLabel(parent),image(im),name(n),theGame(g)
{

    setFixedSize(230,190);

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
    switch(theGame->currentPhase){
    case Game::bonusPhase:
        //place armies on countries
        if (controller == theGame->currentPlayer){//must be controller
            numArmies++;
            theGame->freeArmies--;

            if(theGame->freeArmies == 0){
                if(theGame->isIntro){//if intro then switch players
                    theGame->nextPlayer();

                    if(theGame->currentPlayer->playerID==0){
                        theGame->nextPhase();
                        theGame->isIntro = false;
                        return;
                    }
                    theGame->freeArmies = theGame->getBonusArmies();
                }
                else{ //if not intro then just go to next phase
                    theGame->nextPhase();
                }
            }
        }

        //numArmies++;
        break;
    case Game::attackPhase:
        theGame->setCountry(this);
        break;
    case Game::reinforcePhase:
        if (!theGame->from){ //nothing in from so first click
            if (controller == theGame->currentPlayer){ // first coutry must be controlled by the player
                theGame->from = this;
            }
            //else do nothing because the first target can't be another player
        }
        else{
            if (controller == theGame->currentPlayer){ //in reinforce phase armies move between 2 adjacent countries controlled by the same player
                if(theGame->to->isNeighbor(this)){//check if viable target
                    theGame->to = this;
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
            move(100,200);
            setText(QString(numArmies));
            if(theGame->occipiedTerritories == 42) theGame->nextPhase();
        }
        break;
    }

}
void Country::select(bool sel){
    //change boarder to show selected
}
void Country::setController(Player *p){
    controller = p;
    //do the thing that shows they own the country
}

void Country::mouseMoveEvent(QMouseEvent *ev){

    //move(ev->windowPos().x() - offset.x(),ev->windowPos().y() - offset.y());
}

void Country::mouseReleaseEvent(QMouseEvent *ev){

    std::cout << "Owner: " <<&*controller <<" #Occupied: " << theGame->occipiedTerritories <<" Phase: " << theGame->currentPhase <<
                 " currentPlayer: " <<theGame->currentPlayer->playerID << " Armies: " <<numArmies <<" FreeArmies: " << theGame->freeArmies
              <<std::endl;
}
