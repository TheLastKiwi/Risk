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
    Card *hand[5]={0,0,0,0,0};
    Player(Game *g, int ID);
    int rollDie();
    Card *drawCard();
    int freeArmies =0;
    void updateHand(Card *newHand[5]);
};

#endif // PLAYER_H
