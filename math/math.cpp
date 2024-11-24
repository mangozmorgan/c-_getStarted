#include <iostream>
#include "math.hpp"
using namespace std;



int addition( int a , int b ){
	return a + b;
}

void drawSquare(int height, int width){
	for( int i = 0 ; i < height ; i++ ){

		for ( int j = 0 ; j < width ; j++){
			cout << "*";
		}

		cout << endl;
	}
}

int ajouteDeux(int& a) {
	// si ici on utilise la reference la variable utilisée en argument va prendre la valeur finale, sans le & elle est juste utilisée dans la function mais pas modifiée
    a+=2;
    return a;
}