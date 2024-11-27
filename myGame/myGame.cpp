#include "MyGame.hpp"
#include <iostream>
#include <string>
using namespace std;

// Définition du constructeur
MyGame::MyGame() {
    this->life = 100;  
    this->playerName = "";  
    this->mana = 50; 
}


int MyGame::initGame() {

	string playerName;
	
	cout << "What is your name ?" << endl;
	getline(cin, playerName);

	cout << " Welcome in my awesome Game " << playerName << " !!" << endl;

    return 0;
}

int MyGame::addPlayer(string playerName){
	this->playerName = playerName;

	return 0;
}


// int MyGame::chooseClass(){
	

// 	return 0;
// }
