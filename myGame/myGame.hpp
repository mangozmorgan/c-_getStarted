#ifndef MY_GAME_HPP
#define MY_GAME_HPP
#include <string>
#include <iostream>


class MyGame {

	public:
		MyGame(); // Déclaration du constructeur	
		int initGame();
		int addPlayer(std::string playerName);

	private:
		int life;
		int mana;
		std::string playerName;
	};

#endif
