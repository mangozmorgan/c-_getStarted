#include "./Enemy.hpp"
#include "../Player/Player.hpp"
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

Enemy::Enemy(int playerLevel){

	string randomTypeEnemy = this->getRandomEnemyType();

	cout << "One " << randomTypeEnemy << " appeared" << endl;

	float coef = 1.0f + ( (playerLevel + this->getTypeEnemyCoef(randomTypeEnemy)) / 10.0f);

	this->type = randomTypeEnemy;
	this->life = life *coef;
	this->force = force *coef;

}

int Enemy::getTypeEnemyCoef(string enemyType){	

	if( enemyType == "Orc" ){
		return 2 ;
	}else if ( enemyType == "Squeleton" ){
		return 1;
	}else if ( enemyType == "Dragon" ){
		return 5;
	}else if ( enemyType == "Troll" ){
		return 3;
	}

	return 0 ;

}


void Enemy::reveivedDamages(Enemy& enemy, Player& player) {

	int playerForce = player.getForce(player);

   	enemy.life -= playerForce;
	cout << endl;
	cout << "You Inflict " << playerForce << " of Damage" << endl; 

	if ( enemy.life <= 0 ){
		enemy.isAlive = false ;
		cout << "You kill the " << enemy.getName(enemy) << endl;
	}else{
		cout << "Life of enemy is " << enemy.life << endl;
	}
}

int Enemy::getForce(Enemy &enemy){
	return enemy.force;
}

int Enemy::getEnemyLife(Enemy &enemy){
	return this->life;
}

bool Enemy::getIsAlive(Enemy &enemy){
	return this->isAlive;
}

Enemy Enemy::getRandomEnemy(vector<Enemy> enemiesList) {

    std::srand(std::time(0));	
    int randomIndex = std::rand() % enemiesList.size();

    return enemiesList[randomIndex];
}

string Enemy::getRandomEnemyType() {

    std::srand(std::time(0));	
    int randomIndex = std::rand() % this->typeEnemies.size();

    return typeEnemies[randomIndex];
}

string Enemy::getName(Enemy &enemy){
	return enemy.type;
}

int Enemy::attackPlayer(Player &player, Enemy &enemy){

	player.receiveDamages( player, enemy) ;

	return 0 ;

}



