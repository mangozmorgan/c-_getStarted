#include <iostream>
#include "array.hpp"
#include <vector>
#include <array>
using namespace std;

double testMoyenne(vector<int>& moyennes)
{

   double total(0);

   for( int i = 0 ; i < moyennes.size(); i++){
		total += moyennes[i];
   }

   return total/moyennes.size();
   
}