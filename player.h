#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class Player
{
public:
    int playerID;
    int cardsInHand = 0;
    Card *hand[5];
    Player();
};

#endif // PLAYER_H
