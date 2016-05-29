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
void Player::updateHand(Card *newHand[]){
    for(int i = 0; i < 5; i++){
        if(hand[i] && hand[i]->selected)delete hand[i];
        hand[i] = newHand[i];
    }
    cardsInHand-=3;
}
