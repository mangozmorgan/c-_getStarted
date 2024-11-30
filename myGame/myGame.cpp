#include "MyGame.hpp"
#include "../Enemy/Enemy.hpp"
#include <iostream>
#include <random>
#include <string>
#include <variant>
#include <cstdlib>  
#include <algorithm>
using namespace std;




MyGame::MyGame(const std::string& playerName) : player(playerName) {

    

    system("cls");    
    cout << "***************************************" << endl;
    cout << "Welcome in my awesome Game " << player.getPlayerName() << " !!" << endl;  
    cout << "***************************************" << endl;
    cout << endl;

    int resPartOne = this->partOne();

}

int MyGame::partOne(){
    

    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "You emerge slowly, lying on the cold ground, facing a mysterious and abandoned ruin" << endl; 
    cout << "You decide to come in but you feel something strange" << endl; 
    cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;


    

    
    cout << endl;
    cout << "#######################" << endl;

    Enemy enemy1(1);
    Enemy enemy2(1);

    cout << "#######################" << endl;   
    cout << endl;

    cout << "You have to fight for your life !" << endl; 
    cout << endl;

    this->enemiesList.push_back(enemy1) ; 
    this->enemiesList.push_back(enemy2) ; 
    


    string userChoice("");

    cout << "" << endl;
    cout << "Wanna run or fight ? (r = run, f = fight)" << endl;
    cin >> userChoice;
    cin.ignore();

    if( userChoice == "f" ){
        bool resFight = this->fightPart(this->player, this->enemiesList);

        if( resFight == 0 ){

            cout << "-------------------------" << endl;
            cout << "You win !!!" << endl;
            cout << "-------------------------" << endl;
            cout << endl;
            cout << "Next level or exit ? " << endl;
            cout << "0 : Next level" << endl;
            cout << "1 : exit ? " << endl;

        }else if ( resFight == 2 ){
            this->runaway();
        }else if ( resFight == 3 ){
            cout << "-------------------------" << endl;
            cout << "You loose ..." << endl;
            cout << "-------------------------" << endl;
        }
        
    }else{
        this->runaway();
    }
    
    

    return 0 ;
}

int MyGame::runaway(){
    cout << "-------------------------" << endl;
    cout << "You runaway from the fight ..." << endl;
    cout << "-------------------------" << endl;
    return 0;
}

int MyGame::fightPart(Player &player, vector<Enemy> &enemiesList){   

    bool playerTurn = this->isPlayerFirst();
    int turn = 0;

    system("cls");
    cout << endl;
    cout << "***************************************" << endl;
    cout << "Fight !!!!" << endl;
    cout << "***************************************" << endl;
    cout << endl;

    while(enemiesList.size() > 0){

        turn++;
        cout << "-------------------------" << endl;
        cout << "Round" << turn << endl; 
        cout << "-------------------------" << endl;
        cout << endl;

        string enemyString(" (") ;
        for (int i = 0; i < enemiesList.size(); i++) {
            enemyString += enemiesList[i].getName(enemiesList[i]) ;

            if( enemiesList.size() -1 != i ){
                enemyString += ",";
            }
        }

        enemyString += ")";

        cout << "enemies left : " << enemiesList.size() << enemyString << endl;
        cout << "Your life : " << player.getLife(player) << endl;
        cout << endl;
        Enemy randomEnemy = Enemy::getRandomEnemy(enemiesList);

        if (playerTurn) {

            int userChoice;
            cout << "It's your turn!" << endl;
            cout << endl;
            cout << "What you wanna do ? " << endl;
            array<string, 2>capacitiesList = player.getCapacities(player);

            for( int i = 0 ; i < capacitiesList.size() ; i++){
                cout << i << " : " << capacitiesList[i] << endl ;
            }

            cin >> userChoice ;
            cin.ignore();

            //if player choose attack
            if( userChoice == 0 ) {

                int enemyChoice;

                std::cout << std::endl;
                std::cout << "Ok wich enemy ? " << std::endl;

                for( int i = 0 ; i < enemiesList.size() ; i++ ){
                    cout << i << " : " << enemiesList[i].getName(enemiesList[i]) << endl ;
                }

                cin >> enemyChoice;
                cin.ignore();


                player.attackEnemy(player, enemiesList[enemyChoice]); 

                int enemyLife = enemiesList[enemyChoice].getEnemyLife(enemiesList[enemyChoice]);

                if ( enemiesList[enemyChoice].getEnemyLife(enemiesList[enemyChoice]) <= 0 ){
                    enemiesList.erase(remove_if(enemiesList.begin(), enemiesList.end(), [](Enemy& e) {
                    return !e.getIsAlive(e);
                
                    }), enemiesList.end());
                }

            }else if ( userChoice == 1 ){
                return 1; 
            }
            
            cout << "" << endl;

        }else {
            //TODO : gerer la selection aleatoire de l'ennemi
            Enemy& enemy = enemiesList[0];

            cout << "#######################" << endl;
            std::cout << "It's " << enemy.getName(enemy) << "'s turn!" << std::endl;
            enemy.attackPlayer(player, enemy);
            cout << "#######################" << endl;
            cout << endl;

            if( player.getLife(player) <= 0 ){
                return 3;
            }

        }

        playerTurn = !playerTurn;

    }

    return 0;

}

bool MyGame::isPlayerFirst() {
    // Définir la tendance pour "true" (ici 70% de chances pour "true" et 30% pour "false")
    float chanceForTrue = 0.65f;

    // Créer un générateur de nombres aléatoires entre 0.0 et 1.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 1.0);

    // Tirer un nombre aléatoire entre 0.0 et 1.0
    float randomValue = dis(gen);

    // Si le nombre tiré est inférieur à la chance définie pour "true", retourner true
    return randomValue < chanceForTrue;
}
















