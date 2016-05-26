#ifndef CARD_H
#define CARD_H
#include "QLabel"
class HandWindow;
class Country;
class Card : public QLabel
{
public:
    Card(QString im, HandWindow *parent, int armyID,QString countryName);
    Card(Card *c, HandWindow *p);
    QString country;
    QString image;
    int army;
    bool selected;
    void select();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CARD_H
