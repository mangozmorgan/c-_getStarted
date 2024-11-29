#include "./Enemy.hpp"
#include "../Player/Player.hpp"
#include <iostream>
#include <string>
using namespace std;

Enemy::Enemy(const std::string& type, int life, int force){

	cout << "One " << type << " appeared" << endl;

	this->type = type;
	this->life = life;
	this->force = force;
	this->isAlive = true;

} 

int Enemy::attackEnemy(Enemy &enemy, Player &player) {
	return 0 ;
}


int Enemy::getEnemyLife(Enemy &enemy){
	return this->life;
}

