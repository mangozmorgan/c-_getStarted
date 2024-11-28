#include "enemy/enemy.hpp"


int Enemy::createEnemy(){
	return 0 ;
}

int Enemy::attackEnemy(Enemy &enemy){
	return 0 ;
}


Enemy Enemy::createOrc(){
	return Enemy("Orc", 50, 10, true);
}