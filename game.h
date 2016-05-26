#ifndef GAME_H
#define GAME_H
#include "QHash"
#include "mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "country.h"
#include "attack.h"
#include "reinforce.h"
#include "handwindow.h"
#include "deck.h"
#include "ui_mainwindow.h"
class Game
{
public:
    //Game map and country images stolen from wikipedia
    //Dice images also stolen from wikipedia
    MainWindow *parent;
    HandWindow *handFrame[6];
    QLabel *aDice[3],*dDice[3];
    //TEST
    //Dice *allDice[6];
    //TEST
    bool capturedCountry = false;
    enum Phase {startPhase,bonusPhase,attackPhase,reinforcePhase,endPhase};
    Phase currentPhase;
    Player *players[6];
    int playerCount = 0;
    void setCountry(Country *c);
    bool isIntro = true;
    Deck *deck;//= new Deck(handParent);
    Country *from=0, *to=0;
    Game(MainWindow *p);
    int occupiedTerritories = 0;
    int freeArmies =0;
    int getBonusArmies();
    Player *currentPlayer;
    QHash<QString,Country*> map;
    const QString countryNames[42] = {
        "Alaska",
        "Alberta",
        "Central America",
        "Eastern United States",
        "Greenland",
        "Northwest Territory",
        "Ontario",
        "Quebec",
        "Western United States",
        "Argentina",
        "Brazil",
        "Peru",
        "Venezuela",
        "Great Britain",
        "Iceland",
        "Northern Europe",
        "Scandinavia",
        "Southern Europe",
        "Ukraine",
        "Western Europe",
        "Congo",
        "East Africa",
        "Egypt",
        "Madagascar",
        "North Africa",
        "South Africa",
        "Afghanistan",
        "China",
        "India",
        "Irkutsk",
        "Japan",
        "Kamchatka",
        "Middle East",
        "Mongolia",
        "Siam",
        "Siberia",
        "Ural",
        "Yakutsk",
        "Eastern Australia",
        "Indonesia",
        "New Guinea",
        "Western Australia"
    };
    const QString countryImages[42] = {
        ":/Countries/Pics/NA1.png",
        ":/Countries/Pics/NA2.png",
        ":/Countries/Pics/NA3.png",
        ":/Countries/Pics/NA4.png",
        ":/Countries/Pics/NA5.png",
        ":/Countries/Pics/NA6.png",
        ":/Countries/Pics/NA7.png",
        ":/Countries/Pics/NA8.png",
        ":/Countries/Pics/NA9.png",
        ":/Countries/Pics/SA1.png",
        ":/Countries/Pics/SA2.png",
        ":/Countries/Pics/SA3.png",
        ":/Countries/Pics/SA4.png",
        ":/Countries/Pics/EU1.png",
        ":/Countries/Pics/EU2.png",
        ":/Countries/Pics/EU3.png",
        ":/Countries/Pics/EU4.png",
        ":/Countries/Pics/EU5.png",
        ":/Countries/Pics/EU6.png",
        ":/Countries/Pics/EU7.png",
        ":/Countries/Pics/AF1.png",
        ":/Countries/Pics/AF2.png",
        ":/Countries/Pics/AF3.png",
        ":/Countries/Pics/AF4.png",
        ":/Countries/Pics/AF5.png",
        ":/Countries/Pics/AF6.png",
        ":/Countries/Pics/Asia1.png",
        ":/Countries/Pics/Asia2.png",
        ":/Countries/Pics/Asia3.png",
        ":/Countries/Pics/Asia4.png",
        ":/Countries/Pics/Asia5.png",
        ":/Countries/Pics/Asia6.png",
        ":/Countries/Pics/Asia7.png",
        ":/Countries/Pics/Asia8.png",
        ":/Countries/Pics/Asia9.png",
        ":/Countries/Pics/Asia10.png",
        ":/Countries/Pics/Asia11.png",
        ":/Countries/Pics/Asia12.png",
        ":/Countries/Pics/AU1.png",
        ":/Countries/Pics/AU2.png",
        ":/Countries/Pics/AU3.png",
        ":/Countries/Pics/AU4.png",
    };
    const QString p1Images[42] = {
        ":/P1/P1/NA1.png",
        ":/P1/P1/NA2.png",
        ":/P1/P1/NA3.png",
        ":/P1/P1/NA4.png",
        ":/P1/P1/NA5.png",
        ":/P1/P1/NA6.png",
        ":/P1/P1/NA7.png",
        ":/P1/P1/NA8.png",
        ":/P1/P1/NA9.png",
        ":/P1/P1/SA1.png",
        ":/P1/P1/SA2.png",
        ":/P1/P1/SA3.png",
        ":/P1/P1/SA4.png",
        ":/P1/P1/EU1.png",
        ":/P1/P1/EU2.png",
        ":/P1/P1/EU3.png",
        ":/P1/P1/EU4.png",
        ":/P1/P1/EU5.png",
        ":/P1/P1/EU6.png",
        ":/P1/P1/EU7.png",
        ":/P1/P1/AF1.png",
        ":/P1/P1/AF2.png",
        ":/P1/P1/AF3.png",
        ":/P1/P1/AF4.png",
        ":/P1/P1/AF5.png",
        ":/P1/P1/AF6.png",
        ":/P1/P1/Asia1.png",
        ":/P1/P1/Asia2.png",
        ":/P1/P1/Asia3.png",
        ":/P1/P1/Asia4.png",
        ":/P1/P1/Asia5.png",
        ":/P1/P1/Asia6.png",
        ":/P1/P1/Asia7.png",
        ":/P1/P1/Asia8.png",
        ":/P1/P1/Asia9.png",
        ":/P1/P1/Asia10.png",
        ":/P1/P1/Asia11.png",
        ":/P1/P1/Asia12.png",
        ":/P1/P1/AU1.png",
        ":/P1/P1/AU2.png",
        ":/P1/P1/AU3.png",
        ":/P1/P1/AU4.png",

    };
    const QString p2Images[42] = {
        ":/P2/P2/NA1.png",
        ":/P2/P2/NA2.png",
        ":/P2/P2/NA3.png",
        ":/P2/P2/NA4.png",
        ":/P2/P2/NA5.png",
        ":/P2/P2/NA6.png",
        ":/P2/P2/NA7.png",
        ":/P2/P2/NA8.png",
        ":/P2/P2/NA9.png",
        ":/P2/P2/SA1.png",
        ":/P2/P2/SA2.png",
        ":/P2/P2/SA3.png",
        ":/P2/P2/SA4.png",
        ":/P2/P2/EU1.png",
        ":/P2/P2/EU2.png",
        ":/P2/P2/EU3.png",
        ":/P2/P2/EU4.png",
        ":/P2/P2/EU5.png",
        ":/P2/P2/EU6.png",
        ":/P2/P2/EU7.png",
        ":/P2/P2/AF1.png",
        ":/P2/P2/AF2.png",
        ":/P2/P2/AF3.png",
        ":/P2/P2/AF4.png",
        ":/P2/P2/AF5.png",
        ":/P2/P2/AF6.png",
        ":/P2/P2/Asia1.png",
        ":/P2/P2/Asia2.png",
        ":/P2/P2/Asia3.png",
        ":/P2/P2/Asia4.png",
        ":/P2/P2/Asia5.png",
        ":/P2/P2/Asia6.png",
        ":/P2/P2/Asia7.png",
        ":/P2/P2/Asia8.png",
        ":/P2/P2/Asia9.png",
        ":/P2/P2/Asia10.png",
        ":/P2/P2/Asia11.png",
        ":/P2/P2/Asia12.png",
        ":/P2/P2/AU1.png",
        ":/P2/P2/AU2.png",
        ":/P2/P2/AU3.png",
        ":/P2/P2/AU4.png",

    };
    const QString selImages[42] = {
        ":/Sel/Selected/NA1.png",
        ":/Sel/Selected/NA2.png",
        ":/Sel/Selected/NA3.png",
        ":/Sel/Selected/NA4.png",
        ":/Sel/Selected/NA5.png",
        ":/Sel/Selected/NA6.png",
        ":/Sel/Selected/NA7.png",
        ":/Sel/Selected/NA8.png",
        ":/Sel/Selected/NA9.png",
        ":/Sel/Selected/SA1.png",
        ":/Sel/Selected/SA2.png",
        ":/Sel/Selected/SA3.png",
        ":/Sel/Selected/SA4.png",
        ":/Sel/Selected/EU1.png",
        ":/Sel/Selected/EU2.png",
        ":/Sel/Selected/EU3.png",
        ":/Sel/Selected/EU4.png",
        ":/Sel/Selected/EU5.png",
        ":/Sel/Selected/EU6.png",
        ":/Sel/Selected/EU7.png",
        ":/Sel/Selected/AF1.png",
        ":/Sel/Selected/AF2.png",
        ":/Sel/Selected/AF3.png",
        ":/Sel/Selected/AF4.png",
        ":/Sel/Selected/AF5.png",
        ":/Sel/Selected/AF6.png",
        ":/Sel/Selected/Asia1.png",
        ":/Sel/Selected/Asia2.png",
        ":/Sel/Selected/Asia3.png",
        ":/Sel/Selected/Asia4.png",
        ":/Sel/Selected/Asia5.png",
        ":/Sel/Selected/Asia6.png",
        ":/Sel/Selected/Asia7.png",
        ":/Sel/Selected/Asia8.png",
        ":/Sel/Selected/Asia9.png",
        ":/Sel/Selected/Asia10.png",
        ":/Sel/Selected/Asia11.png",
        ":/Sel/Selected/Asia12.png",
        ":/Sel/Selected/AU1.png",
        ":/Sel/Selected/AU2.png",
        ":/Sel/Selected/AU3.png",
        ":/Sel/Selected/AU4.png",

    };
    const QString diceImages[6] = {
        ":/Dice/Dice/D1.png",
        ":/Dice/Dice/D2.png",
        ":/Dice/Dice/D3.png",
        ":/Dice/Dice/D4.png",
        ":/Dice/Dice/D5.png",
        ":/Dice/Dice/D6.png",
    };

    void takeOver(Player *p, Country *c);
    void nextPhase();
    void showHand();
    //void setTo(Country *c);
    void showDice(int attDice[], int a, int defDice[], int d);


    void setFrom(Country *c){
        //highlight country boarder?
        //highlight possible targets?
        from = c;
    }
    void play(int numPlayers);
    void placeMap(){
        map.value("Western Australia")->move(789,91);
        map.value("Western Australia")->move(1008,446);
        map.value("Indonesia")->move(946,296);
        map.value("Yakutsk")->move(869,43);
        map.value("New Guinea")->move(1065,344);
        map.value("Eastern Australia")->move(1071,433);
        map.value("Ural")->move(727,52);
        map.value("Siberia")->move(791,44);
        map.value("Mongolia")->move(873,134);
        map.value("Siam")->move(919,250);
        map.value("Middle East")->move(647,183);
        map.value("China")->move(829,149);
        map.value("Kamchatka")->move(998,45);
        map.value("India")->move(779,202);
        map.value("Irkutsk")->move(873,88);
        map.value("Afghanistan")->move(727,119);
        map.value("South Africa")->move(577,399);
        map.value("North Africa")->move(458,209);
        map.value("East Africa")->move(637,277);
        map.value("Congo")->move(571,323);
        map.value("Egypt")->move(583,226);
        map.value("Ukraine")->move(629,70);
        map.value("Peru")->move(207,374);
        map.value("Brazil")->move(235,355);
        map.value("Southern Europe")->move(575,151);
        map.value("Western Europe")->move(518,152);
        map.value("Scandinavia")->move(576,70);
        map.value("Northern Europe")->move(564,124);
        map.value("Japan")->move(1062,175);
        map.value("Madagascar")->move(715,419);
        map.value("Iceland")->move(490,82);
        map.value("Great Britain")->move(521,113);
        map.value("Argentina")->move(262,458);
        map.value("Venezuela")->move(177,311);
        map.value("Western United States")->move(61,145);
        map.value("Quebec")->move(245,91);
        map.value("Ontario")->move(175,97);
        map.value("Northwest Territory")->move(95,38);
        map.value("Greenland")->move(332,21);
        map.value("Eastern United States")->move(118,152);
        map.value("Central America")->move(84,229);
        map.value("Alberta")->move(79,99);
        map.value("Alaska")->move(0,50);
    }
    void makeConnections();
    bool controlContinent(int start, int len);
    bool giveControlStart(Country *c);
    void nextPlayer(){
        currentPlayer = players[(currentPlayer->playerID+1) % playerCount];
        parent->ui->lblPlayer->setText(QString("Player " + QString(currentPlayer->playerID+1+48)));
    }
    void endTurn(){

        if(capturedCountry){
            currentPlayer->drawCard();
            showHand();
            nextPlayer();
        }
        capturedCountry = false;
    }

};

#endif // GAME_H
