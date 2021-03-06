#ifndef CARD_H
#define CARD_H
#include "QLabel"
class HandWindow;
class Country;
class Card : public QLabel
{
public:
    Card(QString im, QWidget *parent, int armyID,QString countryName);
    Card(Card *c, QWidget *parent);
    QString country;
    QString image;
    int army;
    bool selected;
    void select();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CARD_H
