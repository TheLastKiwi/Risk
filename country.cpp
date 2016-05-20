#include "country.h"
#include "QBitmap"
#include "game.h"
#include "QMouseEvent"
#include "iostream"
#include "game.h"
Country::Country(QString im, MainWindow *parent, QString n):QLabel(parent),image(im),name(n)
{

    setFixedSize(118,159);

    setPixmap(im);
//    QBitmap q();
    QPixmap d(im);
    setMask(d.mask());
//setScaledContents(true);

}
void Country::mousePressEvent(QMouseEvent* event)
{
    offset=event->localPos().toPoint();
    if(theGame->currentPhase == bonusPhase){
        //place armies on countries
        if (controller == theGame->currentPlayer){//must be controller
            numArmies++;
        }
    }
    else if(theGame->currentPhase == attackPhase){
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
    }
    else if (theGame->currentPhase == reinforcePhase){
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
    }
    else if(theGame->currentPhase == endPhase){
        //not sure about this one
    }


}
void Country::mouseMoveEvent(QMouseEvent *ev){

    move(ev->windowPos().x() - offset.x(),ev->windowPos().y() - offset.y());
}

void Country::mouseReleaseEvent(QMouseEvent *ev){
    std::cout << "map.value(\"" << name.toStdString() << "\")->move(" << x() << "," << y() << ");" <<std::endl;//countryNames[i])"name.toStdString() << " " << x() << " " << y() << std::endl;

}
