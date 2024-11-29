#ifndef MY_GAME_HPP
#define MY_GAME_HPP
#include <string>
#include <vector>
#include <iostream>
#include "../Player/Player.hpp"
#include "../Enemy/Enemy.hpp"
using std::vector;

class MyGame {
	
	public:
		MyGame(const std::string& playerName);
		int partOne();

	private:
		Player player;
		std::vector<Enemy> enemiesList;
};

#endif
