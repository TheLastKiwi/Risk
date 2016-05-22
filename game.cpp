#include "game.h"
#include "cmath"
#include "fstream"
Game::Game(MainWindow *p):parent(p)
{

    for(int i = 0; i < 42; i++){
        map.insert(countryNames[i],new Country(countryImages[i],p,countryNames[i],this));
    }
    makeConnections();
    placeMap();
}
void Game::makeConnections(){
    Country *curr;

    //Can probably find this in the documentation but I found it here
    //https://www.youtube.com/watch?v=sWIQIi4lg58 at 2:40
    QFile myFile(":/Directions/Neighbors.txt");
    myFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&myFile);
    while(!in.atEnd()){
        QString line = in.readLine();
        if(line.startsWith("-")){
            line.remove('-');
            curr->addNeighbor(map.value(line));
        }
        else{
            curr = map.value(line);
        }
    }
    myFile.close();

}
int Game::getBonusArmies(){
    int numControlled = 0;
    int bonus = 0;
    for(int i = 0; i < 42; i++){
        if (map.value(countryNames[i])->controller == currentPlayer) numControlled++;
    }
    bonus = std::max(3,numControlled / 3);
    if(controlContinent(0,9)) bonus +=5;//NA
    if(controlContinent(9,4)) bonus +=2;//SA
    if(controlContinent(13,7)) bonus +=5;//Europe
    if(controlContinent(20,6)) bonus +=3;//Africa
    if(controlContinent(26,12)) bonus +=7;//Asia
    if(controlContinent(38,4)) bonus +=2;//Aus

}
bool Game::controlContinent(int start, int len){
    for(int i = start;i<start+len;i++)   {
        if(map.value(countryNames[i])->controller != currentPlayer){
            return false;
        }
    }
    return true;
}
void Game::play(int numPlayers){
    for(int i = 0; i < numPlayers; i++){
        players[i] = new Player(this,i);
    }
    playerCount = numPlayers;
    currentPlayer = players[0];
    currentPhase = Game::startPhase;

}

bool Game::giveControlStart(Country *c){
    c->controller = currentPlayer;
    int n = (++occipiedTerritories) % playerCount;
    currentPlayer = players[n];
}

void Game::nextPhase(){

    switch(currentPhase){
    case startPhase:
        currentPhase = bonusPhase;
        currentPlayer = players[0];
        //add graphic telling user phase changed
        break;
    case bonusPhase:
        currentPhase = attackPhase;break;
    case attackPhase:
        currentPhase = reinforcePhase;break;
    case reinforcePhase:
        nextPlayer();
    case endPhase:
        nextPlayer();
    }

}
