#include "./Player.hpp"
#include "../Enemy/Enemy.hpp"
#include <string>
using namespace std;


Player::Player(string playerName){

	this->playerName = playerName ;
}

string Player::getPlayerName(){
	return this->playerName;
}


int Player::attackEnemy(Player &player, Enemy &enemy){

	enemy.reveivedDamages( enemy, player) ;

	return 0 ;

}

int Player::getForce(Player &player){
	return player.force;
}

int Player::getLife(Player &player){
	return player.life;
}

array<string, 2> Player::getCapacities(Player &player){
	return player.capacitiesList; 
}

void Player::receiveDamages(Player &player, Enemy &enemy){

	int enemyForce = enemy.getForce(enemy);
	player.life -= enemyForce;
	cout << enemy.getName(enemy) << " Inflict " << enemyForce << " of Damage on you !" << endl; 

	if( player.life <= 0 ){
		cout << enemy.getName(enemy) << " kill you ..." << player.life << endl; 
	}else{
		cout << "Your life is " << player.life << endl; 

	}
}
