#include "game.h"
#include "cmath"
#include "fstream"
#include "ui_mainwindow.h"
//TEST INCLUDE
#include "iostream"
Game::Game(MainWindow *p)
{
    for(int i = 0; i < 42; i++){
        map.insert(countryNames[i],new Country(countryImages[i],selImages[i],p1Images[i],p2Images[i],p,countryNames[i],this));
    }
    makeConnections();
    placeMap();
    parent = p;
    for(int i = 0; i < 3; i++){
        aDice[i] = new QLabel(p);//new Dice(p);//QLabel(parent);
        aDice[i]->setFixedSize(35,35);
        //        allDice[i]->setPixmap(diceImages[i]);
        aDice[i]->move(30+40*i,520);


        dDice[i]= new QLabel(p);//new Dice(p);
        dDice[i]->setFixedSize(35,35);
        dDice[i]->move(30+40*i,590);
    }
    deck = new Deck(this);
    //    for(int i = 0; i < 3; i++){
    //        dDice[i]= new QLabel(p);//new Dice(p);
    //        dDice[i]->setFixedSize(35,35);
    //        dDice[i]->move(30+40*i,440);
    //    }//        aDice[i] = new QLabel(p);
    //        aDice[i]->setFixedSize(35,35);
    //        aDice[i]->setPixmap(diceImages[i]);
    //        aDice[i]->move(30+35*i,400);
    //sa=sa.append(QString(attDice[i]+48)).append(" ");
    //QString(parent->ui->lblDiceAtk->text() + QString(attDice[i]+48) + " "));
}
void Game::takeOver(Player *p, Country *c){
    c->setController(p);
    capturedCountry = true;
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
void Game::showHand(){
    int PID = currentPlayer->playerID;
//    for(int i = 0; i < currentPlayer->cardsInHand;i++){
//        Card *t = currentPlayer->hand[i];
//        currentPlayer->hand[i]=new Card(currentPlayer->hand[i],handFrame[PID]);
//        delete t;
//    }
    handFrame[PID]->show();
    handFrame[PID]->displayHand();
}

void Game::getBonusArmies(){
    //TO DO: show hand and turn in cards
    if(currentPlayer->cardsInHand>0)showHand();
    int numControlled = 0;
    int bonus = 0;
    if(isIntro)bonus=40;
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
    currentPlayer->freeArmies=bonus;
    updateBonusArmiesLabel();
}
bool Game::controlContinent(int start, int len){
    for(int i = start;i<start+len;i++)   {
        if(map.value(countryNames[i])->controller != currentPlayer){
            return false;
        }
    }
    return true;
}
void Game::updateBonusArmiesLabel(){
    parent->ui->lblBonus->setText(QString("Bonus Armies ") + QString(QString::number(currentPlayer->freeArmies)));
}

void Game::play(int numPlayers){
    for(int i = 0; i < numPlayers; i++){
        players[i] = new Player(this,i);
        handFrame[i] = new HandWindow(players[i]); //each player has a hand window
        handFrame[i]->setWindowTitle(QString("Player: ") + QString::number(i+1) + QString(" hand") + QString().sprintf("%08p", handFrame[i]));
        //handFrame[i]->show();
    }
    playerCount = numPlayers;
    currentPlayer = players[0];
    currentPhase = Game::startPhase;

}

bool Game::giveControlStart(Country *c){
    c->controller = currentPlayer;
    c->numArmies++;
    occupiedTerritories++;
    c->setControllerImage();
    //    int n = (++occupiedTerritories) % playerCount;
    //    currentPlayer = players[n];
    setupNextPlayer();
}
void Game::showDice(int attDice[],int a, int defDice[],int d){
    //parent->ui->lblDiceAtk->setText("");
    //parent->ui->lblDiceDef->setText("");
    //QString sa,sd;
    //30,400
    for(int i = 0; i <3;i++ ){
        aDice[i]->setPixmap(QString());
        dDice[i]->setPixmap(QString());
    }
    for(int i = 0; i < a; i++){
        //att dice
        aDice[i]->setPixmap(diceImages[attDice[i]]);
    }
    //parent->ui->lblDiceAtk->setText(sa);
    //70,700
    for(int i = 0; i < d; i++){
        //def dice
        dDice[i]->setPixmap(diceImages[defDice[i]]);
    }
    //parent->ui->lblDiceDef->setText(sd);
}
void Game::nextPhase(){
    //NEED TO CLEAN THIS SHIT UP
    //NEXT PLAYER NEXT PHASE END TURN
    QString thePhase;
    switch(currentPhase){
    case startPhase:
        currentPhase = bonusPhase;
        thePhase = "Bonus Phase";
        //parent->ui->lblPhase->setText("Bonus Phase");
        currentPlayer = players[0];
        getBonusArmies();
        //add graphic telling user phase changed
        break;
    case bonusPhase:
        thePhase = "Attack Phase";
        //parent->ui->lblPhase->setText("Attack Phase");
        currentPhase = attackPhase;break;
    case attackPhase:
        thePhase = "Reinforce Phase";
        //parent->ui->lblPhase->setText("Reinforce Phase");
        currentPhase = reinforcePhase;break;
    case reinforcePhase:
        thePhase = "Bonus Phase";

        //parent->ui->lblPhase->setText("Bonus Phase");
        //currentPhase = bonusPhase;
        endTurn();
        updateBonusArmiesLabel();
        break;
        //    case endPhase:
        //        nextPlayer();
    }
    parent->ui->lblPhase->setText(thePhase);
}
void Game::endTurn(){

    if(capturedCountry){
        currentPlayer->drawCard();
    }
    showHand();
    nextPlayer();
    from=0;to=0;
    capturedCountry = false;

}
void Game::nextPlayer(){
        setupNextPlayer();//changes players and player label
        currentPhase = bonusPhase;
        getBonusArmies();
    }

void Game::setupNextPlayer(){
    currentPlayer = players[(currentPlayer->playerID+1) % playerCount];
    parent->ui->lblPlayer->setText(QString("Player " + QString::number(currentPlayer->playerID+1)));
}

void Game::setCountry(Country *c){
    if(from == c){
        c->select(false);
        from = nullptr;
        return;
    }
    if (!from){ //null
            from = c;
            c->select(true);
            std::cout<<c->name.toStdString()<<std::endl;

        //else do nothing because the first target can't be another player
    }
    else{

                to = c;
                c->select(true);



        //else it's the same player so do nothing here
    }
}

//void Game::setTo(Country *c){

//    switch(currentPhase){
//    case attackPhase:
//    {
//        //maybe have window pop up asking if they are sure
//        //if they chose yes then do this stuff
//        //highlight country boarder
//        to = c;
//        Attack *a = new Attack(from,to);
//        int attDice,defDice; //get number of dice from window or something
//        a->attack(attDice,defDice);
//    }
//        break;
//    case reinforcePhase:
//    {
//        //maybe have window pop up asking if they are sure
//        //if they chose yes then do this stuff
//        //highlight country boarder
//        to = c;
//        Reinforce *r = new Reinforce(from,to);
//        int n = 5;
//        r->move(n);//get n from a form or selection or something
//    }
//        break;
//    }
//}
