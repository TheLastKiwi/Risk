#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "QElapsedTimer"
class Game;
class Player
{
public:
    Game *theGame;
    QElapsedTimer seed;
    int cardsInHand = 0;
    Card *hand[5];
    Player(Game *g);
    int rollDie();
    Card *drawCard();
};

#endif // PLAYER_H
