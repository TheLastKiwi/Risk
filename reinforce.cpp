#include "reinforce.h"

Reinforce::Reinforce(Country *from, Country *to)
{
    this->from = from;
    this->to = to;
}
void Reinforce::move(int n){
    to->numArmies+=n;
    from->numArmies-=n;
    to->setControllerImage();from->setControllerImage();
}

Reinforce::~Reinforce()
{

}

