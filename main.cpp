#include <iostream>
#include "MyGame/MyGame.hpp"
using namespace std;



int main() {

    string playerName;
	
	cout << "Hello ! What is your name ?" << endl;
	getline(cin, playerName);     

    MyGame mySuperGame(playerName);

    

    

    return 0;
}
