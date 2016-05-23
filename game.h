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
    MainWindow *parent;
    HandWindow *handFrame[6];
    bool capturedCountry = false;
    enum Phase {startPhase,bonusPhase,attackPhase,reinforcePhase,endPhase};
    Phase currentPhase;
    Player *players[6];
    int playerCount = 0;
    void setCountry(Country *c);
    bool isIntro = true;
    Deck *deck;// = new Deck(handParent);
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

    void nextPhase();
    void showHand();
    void setTo(Country *c);

    void setFrom(Country *c){
        //highlight country boarder?
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
};

#endif // GAME_H
