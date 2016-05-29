#ifndef REINFORCE_H
#define REINFORCE_H
#include "country.h"

class Reinforce
{
public:
    Country *from, *to;
    Reinforce(Country *from, Country *to);
    ~Reinforce();
    void move(int n);
};

#endif // REINFORCE_H
