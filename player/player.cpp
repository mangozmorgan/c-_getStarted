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


int Player::attackEnemy(Player& player, Enemy& enemy){

	enemy.reveivedDamages(enemy, player) ;

}
