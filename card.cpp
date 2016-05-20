#include "card.h"
#include "QBitmap"
Card::Card(QString im, MainWindow *parent):QLabel(parent)
{
    setFixedSize(71,96);
    setPixmap(im);

}
