#include "myGame.hpp"
#include "../player/player.hpp"
#include <iostream>
#include <string>
using namespace std;


MyGame::MyGame(){
    // Initialise des valeurs par défaut si nécessaire
}

int MyGame::initGame() {
	
	string playerName;
	
	cout << "Hello ! What is your name ?" << endl;
	getline(cin, playerName);

	this->player = Player(playerName);

	cout << " Welcome in my awesome Game " << playerName << " !!" << endl;

    return 0;
}






