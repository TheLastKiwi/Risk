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

    if(to->numArmies == 0){
        to->setController(from->controller);
    }
}
