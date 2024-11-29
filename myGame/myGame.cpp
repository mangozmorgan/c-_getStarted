#include "MyGame.hpp"
#include "../Enemy/Enemy.hpp"
#include <iostream>
#include <string>
using namespace std;




MyGame::MyGame(const std::string& playerName) : player(playerName) {
    
    cout << "Welcome in my awesome Game " << player.getPlayerName() << " !!" << endl;  

}

int MyGame::partOne(){

    cout << "You emerge slowly, lying on the cold ground, facing a mysterious and abandoned ruin" << endl; 

    
    cout << "You decide to come in but you feel something strange" << endl; 

    Enemy enemy1("Orc", 100, 20);
    Enemy enemy2("Squeleton", 60, 10);

    cout << "You have to fight for your life !" << endl; 

    this->enemiesList.push_back(enemy1) ; 
    this->enemiesList.push_back(enemy2) ; 
}












