#ifndef ATTACK_H
#define ATTACK_H
#include "country.h"

class Attack
{
public:
    Game *theGame;
    Country *from,*to;
    Attack(Country *from, Country *to);
    void attack(int attackDice, int defDice);
    void sort(int at[3], int ad, int def[2], int dd);
    ~Attack();
};

#endif // ATTACK_H
