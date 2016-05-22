#ifndef HANDWINDOW_H
#define HANDWINDOW_H

#include <QMainWindow>
#include "player.h"
class Card;
namespace Ui {
class HandWindow;
}

class HandWindow : public QMainWindow
{
    Q_OBJECT

public:
    HandWindow(Player *p, QWidget *parent=0);
    Card *selectedHand[3];
    ~HandWindow();
    bool isSet(Card *hand[3]);
    void placeCard(Card *c, int i);
private slots:
    void on_pushButton_clicked();

private:
    Ui::HandWindow *ui;
};
#endif //HANDWINDOW_H
