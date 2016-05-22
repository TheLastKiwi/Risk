#include "player.h"
#include "game.h"
Player::Player(Game *g, int ID)
{
    playerID = ID;
    theGame = g;
    qsrand(seed.nsecsElapsed());
    seed.start();
}

int Player::rollDie(){
    return (qrand() % 6)+1;
}

Card *Player::drawCard(){
    hand[cardsInHand++] = theGame->deck->drawCard();
}
