#ifndef DECK_H
#define DECK_H
#include "handwindow.h"
class Card;
class Deck
{
public:
    Deck(HandWindow *handParent);
    int cardsInDeck = 42;
    Card *deck[42];
    Card *drawCard();
    void shuffle();
    QString cardImages[42];
};

#endif // DECK_H
