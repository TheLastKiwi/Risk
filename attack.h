#ifndef ATTACK_H
#define ATTACK_H
#include "country.h"

class Attack
{
public:
    Country *from,*to;
    Attack(Country *from, Country *to);
    void attack(int attackDice, int defDice);
    void sort(int at[3], int def[2]);
    ~Attack();
};

#endif // ATTACK_H
