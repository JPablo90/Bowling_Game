#include "Quadrant.hpp"

Quadrant::Quadrant(){
	score = 0;
	accum_val =0;
}

Quadrant::~Quadrant(){

}

void Quadrant::setScore(int sc){
	score = sc;
}

int Quadrant::getScore(){
	return score;
}

void Quadrant::setAccumVal(int av){
	accum_val = av;
}

int Quadrant::getAccumVal(){
	return accum_val;
}
