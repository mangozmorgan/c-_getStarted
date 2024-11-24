#include <iostream>
#include <string>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

using namespace std;

// Fonction pour mélanger les lettres d'un mot
string mixingLetters(string word) {
    string melange;
    int position(0); 

    while (!word.empty()) {
        position = rand() % word.size(); 
        melange += word.at(position);    
        word.erase(position, 1);         
    }

    return melange; 
}

int main() {
    srand(time(0)); 
    
    string userWord; // Mot saisi par l'utilisateur
    string trying;   // Tentative de l'utilisateur

    cout << "Enter a mystery word: ";
    cin >> userWord;

    // Mélange du mot saisi
    string mysteryWord = mixingLetters(userWord);

    // Boucle jusqu'à ce que l'utilisateur trouve le mot
    while (userWord != trying) {
        cout << "Try to find the mystery word: " << mysteryWord << endl;
        cin >> trying;



        // Vérification
        if (userWord != trying) {
            cout << "Error, please try again!" << endl;
        }
    }

    cout << "GG bro'!" << endl;

    return 0;
}
