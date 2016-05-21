#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    theGame = new Game(this);
    theGame->play(2);
    /* 3 phases

        Get armies
            -Armies for Math.max(3,Math.floor(countries you control / 3))
                -Armies /3 round down or minimum of 3
            -Bonus armies for controlling entire continents
                -Asia   7
                -NA     5
                -Europe 5
                -Africa 3
                -Australia 2
                -S.America 2
            -Turn in cards
                -If player has 5 cards, you must turn in a set
                -3 Cards turned in mush have one of the following:
                    -3 of the same unit shown(solider, horse, cannon)
                    -3 different units shown(1 of each, or wild card)

                    - Get +2 armies to each country you own on turned in cards

        Attack players
            -Pick number of armies to attack with
            -Pick adjacent country to attack
                -Dice
                    -Attacker can attack with up to n-1 armies
                    -Attacker can use up to Math.min(attackingNum,3)
                        -Can use between 1 and 3 dice depending on number of attackers
                    -Defender can use up to Math.min(defendingNum,2)
                        -can use between 1 and 2 dice depending on number of defenders
                -Roll
                    -Match highest vs highest
                    -Defender wins ties
                    -Countries lose appropriate 1 army for roll lost
                -If defender has 0 armies
                    -Attacker moves any number of armies from numDice to n-1
                -else
                    -Continue attack phase
            -End attack phase
         Fortify countries
            -Player can up to n-1 armies from any country to any adjacent country that player controlls
            -After fortifying turn automatically ends

         End turn
            -Next player starts phase 1
            -If next player has 0 armies, skip to next available player

         Win Condition
            -If a single player controls all countries that player wins

                -Potentially do secret missions
     */

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
    theGame = new Game(this);
}
