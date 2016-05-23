#ifndef ATTACK_H
#define ATTACK_H
#include "country.h"

class Attack
{
public:
    Country *from,*to;
    Attack(Country *from, Country *to);
    void attack(int attackDice, int defDice);
    ~Attack();
};

#endif // ATTACK_H
