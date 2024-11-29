#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <iostream>
class Player; // evite la dépendance circulaire

class Enemy{

	public:
		Enemy(const std::string& type, int life, int force);
		int attackEnemy(Enemy &enemy, Player &player);
		int getEnemyLife(Enemy& enemy);
		int reveivedDamages(Enemy& enemy, Player& player);


	private: 
		std::string type;
		int life;
		int force;
		bool isAlive;
};




#endif
