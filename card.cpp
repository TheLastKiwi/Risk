#include "card.h"
#include "QBitmap"
#include "mainwindow.h"
#include "handwindow.h"
Card::Card(QString im, HandWindow *parent):QLabel(parent)
{
    setFixedSize(71,96);
    setPixmap(im);

}
