#include "card.h"
#include "QBitmap"
Card::Card(QString im, HandWindow *parent):QLabel(0)
{
    setFixedSize(71,96);
    setPixmap(im);

}
