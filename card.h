#ifndef CARD_H
#define CARD_H
#include "QLabel"
#include "mainwindow.h"
class Country;
class Card : public QLabel
{
public:
    Card(QString im, MainWindow *parent);
    Country *country=0;
    int army;
    bool selected;
};

#endif // CARD_H
