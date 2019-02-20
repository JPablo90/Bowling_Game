#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	double pt = 0, st = 0, total = 0;
	vector<int> puntuación;

	for (int i = 0; i < 10; ++i)
	{
		if(i!=9){
			cin >> pt;
			cin >> st;
			if(pt==10){
				total+=10;
			}
			if(pt+st < 10){
				total +=pt+st;
			}
			if(pt+st ==10){
				total+=10;
			}
		}
		else{

		}
	}

	return 0;
}