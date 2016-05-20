#ifndef GAME_H
#define GAME_H
#include "QHash"
#include "mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "country.h"
#include "attack.h"
#include "reinforce.h"
class Game
{
public:
    MainWindow *parent;
    enum Phase {bonusPhase,attackPhase,reinforcePhase,endPhase};
    Phase currentPhase;
    Country *from, *to;
    Game(MainWindow *p);
    int freeArmies =0;
    int getArmies();
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
    void setTo(Country *c){

        switch(currentPhase){
        case attackPhase:
        {
            //maybe have window pop up asking if they are sure
            //if they chose yes then do this stuff
            //highlight country boarder
            to = c;
            Attack *a = new Attack(from,to);
            int attDice,defDice; //get number of dice from window or something
            a->attack(attDice,defDice);
        }
            break;
        case reinforcePhase:
        {
            //maybe have window pop up asking if they are sure
            //if they chose yes then do this stuff
            //highlight country boarder
            to = c;
            Reinforce *r = new Reinforce(from,to);
            int n = 5;
            r->move(n);//get n from a form or selection or something
        }
            break;
        }
    }
    void setFrom(Country *c){
        //highlight country boarder?
        from = c;
    }

    void placeMap(){
        Country *c = map.value("South America");
        c->move(209,410);
    }
    void makeConnections();
    QString get(QString s){
        for(int i = 0; i < 42;i++){

        }
        return countryNames[1];
    }
    QString getImage(QString s){

    }
    bool controlCont(int start, int len);
};

#endif // GAME_H
