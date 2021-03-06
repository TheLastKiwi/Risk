#include "deck.h"
#include "card.h"
#include "game.h"
#include "windows.h"
Deck::Deck(Game *g)
{
    qsrand(GetTickCount());
    theGame = g;
    //QString im, HandWindow *parent, int cardNum,QString countryName
    for(int i = 0; i < 42; i++){
        deck[i] = new Card(cardImages[i],theGame->parent,armyVal[i],g->countryNames[i]);
        deck[i]->move(-150,-150);
//        if(i<21){
//        deck[i]->move(50*i,50);
//        }
//            else{
//            deck[i]->move((50*i)-1000,130); //never going to be seen with null parrent

//        }
    }
    shuffle();

}

Card *Deck::drawCard(){
    if (cardsInDeck == 0){
        cardsInDeck = 42;
        shuffle();shuffle();
    }
    Card *c = deck[--cardsInDeck];

    return new Card(c,theGame->handFrame[theGame->currentPlayer->playerID]);
}

void Deck::shuffle(){
    Card *c;
    int swapPos;

    for(int i = 0; i < 42; i++){

        swapPos = qrand()%42;

        c = deck[i];
        deck[i] = deck[swapPos];
        deck[swapPos] = c;
    }
}
