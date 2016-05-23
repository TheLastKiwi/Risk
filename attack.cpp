#include "attack.h"
//TEST INCLUDES
#include "iostream"
//TEST INCLUDES
Attack::Attack(Country *from, Country *to)
{
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

    int attLoss=0,defLoss=0;
    for(int i =0; i < std::min(attackDice,defDice); i++){
        if(attacker[i]<defender[i]){
            attLoss++;
        }
        else{
            defLoss++;
        }
    }
    from->numArmies-=attLoss;
    to->numArmies-=defLoss;
    if(to->numArmies <= 0){
        to->setController(from->controller);
    }
}

void Attack::sort(int at[], int def[]){

}
