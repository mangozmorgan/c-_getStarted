#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>

class Player; // evite la dépendance circulaire

class Enemy{

	public:

		Enemy(int playerLevel);
		
		int getEnemyLife(Enemy &enemy);
		void reveivedDamages(Enemy &enemy, Player &player);
		int getForce(Enemy &enemy);
		static  std::string getName(Enemy &enemy);
		static Enemy getRandomEnemy(std::vector<Enemy> enemiesList);
		int attackPlayer(Player &player, Enemy &enemy);
		bool getIsAlive(Enemy &enemy);
		int getTypeEnemyCoef(std::string enemyType);
		std::string getRandomEnemyType();

	private: 
		std::string type;
		int life = 50;
		int force = 20;
		bool isAlive = true;
		std::array<std::string, 4> typeEnemies = {{
			"Squeleton",
			"Orc",
			"Troll",
			"Dragon"
		}};
		
};




#endif
