#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <iostream>

class Enemy{

	public:
		Enemy(std::string type, int life, int force, bool isAlive){};
		int createEnemy();
		Enemy createOrc();
		int attackEnemy(Enemy &enemy);


	private: 
		std::string type;
		int life;
		int force;
		bool isAlive;
};




#endif
