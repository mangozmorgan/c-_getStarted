#ifndef MY_GAME_HPP
#define MY_GAME_HPP
#include <string>
#include <iostream>
#include "../player/player.hpp"


class MyGame {

	public:
		MyGame();
		int initGame();

	private:
		Player player;
	};

#endif
