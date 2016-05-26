#ifndef DECK_H
#define DECK_H
#include "handwindow.h"
class Card;
class Deck
{
public:
    Deck(Game *g);
    Game *theGame;
    int cardsInDeck = 42;
    Card *deck[42];
    Card *drawCard();
    void shuffle();
    //Soldier http://www.clker.com/clipart-163011.html
    //Calvalry http://cliparts.co/clipart/2938038
    //Cannon http://www.clipartbest.com/clipart-4cbMyMEni
    QString cardImages[42]={
        ":/Cards/Cards/NA1.png",
        ":/Cards/Cards/NA2.png",
        ":/Cards/Cards/NA3.png",
        ":/Cards/Cards/NA4.png",
        ":/Cards/Cards/NA5.png",
        ":/Cards/Cards/NA6.png",
        ":/Cards/Cards/NA7.png",
        ":/Cards/Cards/NA8.png",
        ":/Cards/Cards/NA9.png",
        ":/Cards/Cards/SA1.png",
        ":/Cards/Cards/SA2.png",
        ":/Cards/Cards/SA3.png",
        ":/Cards/Cards/SA4.png",
        ":/Cards/Cards/EU1.png",
        ":/Cards/Cards/EU2.png",
        ":/Cards/Cards/EU3.png",
        ":/Cards/Cards/EU4.png",
        ":/Cards/Cards/EU5.png",
        ":/Cards/Cards/EU6.png",
        ":/Cards/Cards/EU7.png",
        ":/Cards/Cards/AF1.png",
        ":/Cards/Cards/AF2.png",
        ":/Cards/Cards/AF3.png",
        ":/Cards/Cards/AF4.png",
        ":/Cards/Cards/AF5.png",
        ":/Cards/Cards/AF6.png",
        ":/Cards/Cards/Asia1.png",
        ":/Cards/Cards/Asia2.png",
        ":/Cards/Cards/Asia3.png",
        ":/Cards/Cards/Asia4.png",
        ":/Cards/Cards/Asia5.png",
        ":/Cards/Cards/Asia6.png",
        ":/Cards/Cards/Asia7.png",
        ":/Cards/Cards/Asia8.png",
        ":/Cards/Cards/Asia9.png",
        ":/Cards/Cards/Asia10.png",
        ":/Cards/Cards/Asia11.png",
        ":/Cards/Cards/Asia12.png",
        ":/Cards/Cards/AU1.png",
        ":/Cards/Cards/AU2.png",
        ":/Cards/Cards/AU3.png",
        ":/Cards/Cards/AU4.png",

    };

    //I messed up with the images and am not going back to change them
    int armyVal[42] = {2,2,1,1,0,0,0,2,1,0,2,1,0,2,0,0,1,1,2,2,1,2,1,0,1,0,1,0,2,1,2,0,1,0,2,1,2,0,2,1,1,2};
};

#endif // DECK_H
