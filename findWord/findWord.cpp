#include <string>
#include <iostream>
#include "findWord.hpp"
#include <time.h>
using namespace std;

string mixingLetters(string word){
	
		string melange;
		int position(0); 

		while (!word.empty()) {
			position = rand() % word.size(); 
			melange += word.at(position);    
			word.erase(position, 1);         
		}

		return melange; 
}

int findWord(){
	
	srand(time(0)); 
    
    string userWord; 
    string trying;  

    cout << "Enter a mystery word: ";
    cin >> userWord;


    string mysteryWord = mixingLetters(userWord);

    while (userWord != trying) {

		cout << "Try to find the mystery word: " << mysteryWord << endl;
		cin >> trying;



		// Vérification
		if (userWord != trying) {
			cout << "Error, please try again!" << endl;
		}
    }

    cout << "GG bro'!" << endl;
	

	return 0 ;
}

