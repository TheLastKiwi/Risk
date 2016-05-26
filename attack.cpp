#include "attack.h"
//#include "ui_mainwindow.h"
#include "game.h"
//TEST INCLUDES
#include "iostream"
//TEST INCLUDES


Attack::Attack(Country *from, Country *to)
{
    theGame = from->theGame;
    this->from=from;
    this->to = to;
}

Attack::~Attack()
{

}

void Attack::attack(int attackDice, int defDice){
    std::cout << from->name.toStdString() << " attacks " << to->name.toStdString() <<std::endl;
    int attacker[3];
    int defender[2];
    for(int i = 0; i < attackDice; i++){
        attacker[i] = qrand() % 6;
    }
    for(int i = 0; i < defDice; i++){
        defender[i] = qrand() % 6;
    }
    sort(attacker,attackDice,defender,defDice);

    theGame->showDice(attacker,attackDice,defender,defDice);

    int attLoss=0,defLoss=0;
    for(int i =0; i < std::min(attackDice,defDice); i++){
        if(attacker[i]<=defender[i]){
            attLoss++;
        }
        else{
            defLoss++;
        }
    }
    from->numArmies-=attLoss;
    to->numArmies-=defLoss;
    if(to->numArmies <= 0){
        //to->setController(from->controller);
        theGame->takeOver(from->controller,to);
    }
    to->setControllerImage();from->setControllerImage();
}

void Attack::sort(int at[], int ad, int def[], int dd){
    if(ad==2){
        if(at[1] > at[0]){
            int t = at[1];
            at[1] = at[0];
            at[0]=t;
        }
    }
    if(ad==3){
        if(at[1] > at[0]){
            int t = at[1];
            at[1] = at[0];
            at[0]=t;
        }
        if(at[2] > at[0]){
            int t = at[2];
            at[2] = at[0];
            at[0]=t;
        }
        //now at[0] is greatest
        if(at[2] > at[1]){
            int t = at[2];
            at[2] = at[1];
            at[1]=t;
        }
    }

    if(dd==2){
        if(def[1] > def[0]){
            int t = def[1];
            def[1] = def[0];
            def[0]=t;
        }
    }
    if(dd==3){
        if(def[1] > def[0]){
            int t = def[1];
            def[1] = def[0];
            def[0]=t;
        }
        if(def[2] > def[0]){
            int t = def[2];
            def[2] = def[0];
            def[0]=t;
        }
        //now at[0] is greatest
        if(def[2] > def[1]){
            int t = def[2];
            def[2] = def[1];
            def[1]=t;
        }
    }
}
