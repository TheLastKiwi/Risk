#include "game.h"
#include "cmath"
Game::Game(MainWindow *p):parent(p)
{
    Country *c = new Country(":/Countries/Pics/SA.png",p,"South America");
    map.insert("South America",c);
    placeMap();
}
void Game::makeConnections(){
    Country *curr;

    QFile f(":/Directions/Neighbors.txt");
    QTextStream in(&f);
    while(!in.atEnd()){
        QString line = in.readLine();

        QString strCountry = get(line.remove('-'));
        if(line.startsWith("-")){

            if(!map.contains(strCountry)){
                map.insert(strCountry,new Country(getImage(strCountry),parent,strCountry));
            }
            curr->addNeighbor(map.value(strCountry));
        }
        else{
            if(!map.contains(get(strCountry))){
                 map.insert(strCountry,new Country(getImage(strCountry),parent,strCountry));
            }
            curr = map.value(strCountry);
        }



    }
}

int Game::getArmies(){
    int numControlled = 0;
    int bonus = 0;
    for(int i = 0; i < 42; i++){
        if (map.value(countryNames[i])->controller == currentPlayer) numControlled++;
    }
    bonus = std::max(3,numControlled / 3);
    if(controlCont(0,9)) bonus +=5;//NA
    if(controlCont(9,4)) bonus +=2;//SA
    if(controlCont(13,7)) bonus +=5;//Europe
    if(controlCont(20,6)) bonus +=3;//Africa
    if(controlCont(26,12)) bonus +=7;//Asia
    if(controlCont(38,4)) bonus +=2;//Aus

}
bool Game::controlCont(int start, int len){
    for(int i = start;i<start+len;i++)   {
        if(map.value(countryNames[i])->controller != currentPlayer){
            return false;
        }
    }
    return true;
}
