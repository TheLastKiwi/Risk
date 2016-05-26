#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "QElapsedTimer"
class Game;
class Player
{
public:
    int playerID;
    Game *theGame;
    QElapsedTimer seed;
    int cardsInHand = 0;
    Card *hand[5];
    Player(Game *g, int ID);
    int rollDie();
    Card *drawCard();
    int freeArmies =0;
};

#endif // PLAYER_H
