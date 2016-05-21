#ifndef CARD_H
#define CARD_H
#include "QLabel"
class HandWindow;
class Country;
class Card : public QLabel
{
public:
    Card(QString im, HandWindow *parent);
    Country *country=0;
    int army;
    bool selected;
};

#endif // CARD_H
