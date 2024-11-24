#include "writeFile.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <thread>      
#include <chrono>       
using namespace std;

int init(){

	string choice;
	cout << "What do u want to do ? (w = write, r = read) :" << endl ;
	cin >> choice;

	if( choice == "w" ){
		write();
	}else if( choice == "r" ){

		string mode;
		bool byWord(false);
		cout << "Wich mode ? (w = by characters, n = normal)" << endl;

		cin >> mode;

		if( mode == "w" ){
			byWord = true;
		}else{
			cout << "Erreur a gerer " << endl;
		}

		read(byWord);
	}

	return 0;

}

int write() {
    string content;

    cout << "What do you want to write? :" << endl;
    cin.ignore(); 

    getline(cin, content);
    ofstream monFlux("./scores.txt", ios::app);

    if (monFlux) {
        monFlux << content << endl;
        monFlux.close(); 
    } else {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }

    return 0;
}


int read( bool byWord ){
	
   ifstream file("./scores.txt");
   
   if ( file ){
		file.seekg(10);
		string ligne;

		
		int *pointer(0);
		pointer = new int;
		*pointer = 0;

		if( byWord ){
			char a ;
			
			while ( file.get(a) ){
				++ *pointer ;
				cout << a ;
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
		}else{
			while( getline(file, ligne) ){
				cout << ligne << endl;
			}
		}	

		cout << "Adresse de la variable : " << &pointer << endl ;	
		cout << "Nombre de lettres : " << *pointer << endl ;	
		cout << "Adresse du pointer : " << pointer << endl ;

		delete pointer; 

		file.close();

   }else{
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

   return 0;
}