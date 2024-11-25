#include "writeFile.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>      
#include <chrono>   

using namespace std;
namespace fs = std::filesystem;

int init(){

	bool isFinished(false);

	while( !isFinished ){

		string choice;
		cout << "What do u want to do ? (w = write, r = read) :" << endl ;
		cin >> choice;
		cin.ignore();

		if( choice == "w" ){

			write();

		}else if( choice == "r" ){

			string mode;
			bool byWord(false);

			cout << "Wich mode ? (w = by characters, n = normal)" << endl;

			cin >> mode;
			cin.ignore();

			if( mode == "w" ){
				byWord = true;
			}else{
				cout << "Erreur a gerer " << endl;
			}

			read(byWord);
		}


		cout << "Another task ? (y = yes, n = exit) :" << endl ;
		cin >> choice;

		if( choice == "n" ){
			isFinished = true;
			cout << "See yah !" << endl ;
		}

	}
	

	return 0;

}

int listFiles(){

	for (const auto& entry : fs::directory_iterator("./logs")) {

        if (fs::is_regular_file(entry.status())) {
            std::cout << "- " << entry.path().filename() << std::endl;
        }
    }

	return 0;
}

int write() {

	string baseFilename("./logs/");
	int typeOpen(1);
	string filename;
	bool isFinish(false);

	cout << "Do you wanna create a new file or update one ? " << endl;
	cout << "1 = new file, 2 = update file" << endl;

	cin >> typeOpen;
	cin.ignore(); 

	if( typeOpen == 1 ){


		cout << "Wich Filename ? " << endl;
		getline(cin, filename);

	}else if ( typeOpen == 2 ){

		cout << "Wich File ? " << endl;


		listFiles();

		getline(cin, filename);
	}
	

    string content;

    cout << "What do you want to write? :" << endl;


    getline(cin, content);
    ofstream monFlux(baseFilename + filename, ios::app);

    if (monFlux) {
        monFlux << content << endl;
        monFlux.close(); 
		cout << "Operation success" << endl;
    } else {
        cout << "Cannot open the file: " << baseFilename + filename << endl;
    }

    return 0;
}


int read( bool byWord ){

	string filename;
	cout << "Wich File ? " << endl;
	listFiles();
	getline(cin, filename);
	
   ifstream file("./logs/"+filename);
   
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