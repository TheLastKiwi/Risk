#include "deck.h"
#include "card.h"
Deck::Deck(HandWindow *handParent)
{
for(int i = 0; i < 42; i++){
    deck[i] = new Card(cardImages[i],handParent);
}
}

Card *Deck::drawCard(){
    return deck[--cardsInDeck];
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
