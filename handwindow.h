#ifndef HANDWINDOW_H
#define HANDWINDOW_H

#include <QDialog>
#include "card.h"
#include "player.h"
namespace Ui {
class HandWindow;
}

class HandWindow : public QDialog
{
    Q_OBJECT

public:
    HandWindow(Player *p, QWidget *parent =0);
    Card *selectedHand[3];
    ~HandWindow();
    bool isSet(Card *hand[3]);
    void placeCard(Card *c, int i);
private slots:
    void on_pushButton_clicked();

private:
    Ui::HandWindow *ui;
};

#endif // HANDWINDOW_H
