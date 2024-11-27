#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <iostream>

class Enemy{

	public:
		int createEnemy();
		int attackEnemy(Enemy &enemy);


	private: 
		std::string name;
		int force;
		int life;
		std::string specialAttack;
		bool isAlive;
};




#endif
