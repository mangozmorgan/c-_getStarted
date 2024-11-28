#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>




class Player {

	public:
		Player();
		Player(std::string playerName);

	private: 
		std::string playerName;
		int life = 100;
		int force = 50;
};



#endif