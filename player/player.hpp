#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>




class Player {

	public:
		Player(std::string playerName);
		std::string getPlayerName();
		int attackEnemy(Player& player, Enemy& enemy);


	private: 
		std::string playerName;
		int life = 100;
		int force = 50;
};



#endif