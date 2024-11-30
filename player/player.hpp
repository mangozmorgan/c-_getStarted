#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <array>
#include "../Enemy/Enemy.hpp"



class Player {

	public:
		Player(std::string playerName);
		std::string getPlayerName();
		int attackEnemy(Player& player, Enemy& enemy);
		void receiveDamages(Player& player, Enemy& enemy);
		int getForce(Player &player);
		int getLife(Player &player);
		std::array<std::string, 2> getCapacities(Player &player);


	private: 
		std::string playerName;
		int life = 1000;
		int force = 50;
		std::array<std::string, 2> capacitiesList = {"Attack", "Run"};
};



#endif