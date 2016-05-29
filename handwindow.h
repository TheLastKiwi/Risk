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
    Player *thePlayer;
    bool isSet(Card *hand[3]);
//    void placeCard(Card *c, int i);
    void displayHand();
    int countSelectedCards(){
        int s = 0;
        for(int i=0; i < 5; i++){
            if(thePlayer->hand[i] && thePlayer->hand[i]->selected)
                s++;
        }
        return s;
    }
    void setSelectedHand(){
        int num = 0;
        for(int i = 0; i < 5; i++){
            if(thePlayer->hand[i] && thePlayer->hand[i]->selected)
                selectedHand[num++] = thePlayer->hand[i];
        }
    }

int getBonusTurninAmount();
private slots:
    void on_btnTurnIn_clicked();
    void on_btnClose_clicked();

private:
    Ui::HandWindow *ui;

};
#endif //HANDWINDOW_H
