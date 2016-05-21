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
    for(int i = 0; i < neighborCounter; i++){
        if (neighbors[i]->isVisible()){
            neighbors[i]->hide();
        }
        else{
            neighbors[i]->show();
        }

    }
    offset=event->localPos().toPoint();
    switch(theGame->currentPhase){
    case Game::bonusPhase:
        //place armies on countries
        if (controller == theGame->currentPlayer){//must be controller
            numArmies++;

        }
        numArmies++;
        break;
    case Game::attackPhase:
        if (!theGame->from){ //nothing in from so first click
            if (controller == theGame->currentPlayer){ // first coutry must be controlled by the player
                theGame->from = this;
            }
            //else do nothing because the first target can't be another player
        }
        else{
            if (controller != theGame->currentPlayer){ //in attack phase you can't attack yourself
                if(theGame->to->isNeighbor(this)){//check if viable target
                    theGame->to = this;
                }
            }
            //else it's the same player so do nothing here
        }
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
            theGame->occipiedTerritories++;
        }

        break;
    }

}
void Country::mouseMoveEvent(QMouseEvent *ev){

    //move(ev->windowPos().x() - offset.x(),ev->windowPos().y() - offset.y());
}

void Country::mouseReleaseEvent(QMouseEvent *ev){
    //std::cout << "map.value(\"" << name.toStdString() << "\")->move(" << x() << "," << y() << ");" <<std::endl;//countryNames[i])"name.toStdString() << " " << x() << " " << y() << std::endl;
    std::cout << numArmies << std::endl;
}
