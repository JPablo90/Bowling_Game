#include "Bowling_Game.hpp"

Bowling_Game::Bowling_Game(){
	input1 = 0;
	input2 = 0;
	totalScore = 0;
}

Bowling_Game::~Bowling_Game(){
	if(Qd.size() > 0)Qd.clear();
}

int Bowling_Game::setInput1(int I1){
	if(I1 < 0 || I1 > 10){
		std::cout << "Choise a value between 0 and 10" << std::endl;
		return 1;
	}
	input1 = I1;
	return 0;
}
		
int Bowling_Game::getInput1(){
	return input1;
}

int Bowling_Game::setInput2(int I2){
	if(I2 < 0 || I2 > 10){
		std::cout << "This is not a good value for input 2" << std::endl;
		return 1;
	}
	input1 = I2;
	return 0;
}

int Bowling_Game::getInput2(){
	return input2;
}

void Bowling_Game::setTotalScore(int TS){
	if(TS < 0)totalScore = 0;
	else{
		totalScore = TS;
	}
}

int Bowling_Game::getTotalScore(){
	return totalScore;
}

void Bowling_Game::startGame(){
	int I1 = 0, I2 = 0, I3 = 0, isBValue = 0;
	for(unsigned int i = 0; i < 10;i++){
		while(isBValue == 0){
			if(i < 9){
				std::cin >> I1 >> I2;
				if(setInput1(I1) == 0 && setInput2(I2) == 0) {
					eval_Inputs(I1, I2, i);
					isBValue = 1;
				}
			}
			else{
				std::cin >> I1 >> I2;
				if(setInput1(I1) == 0 && setInput2(I2) == 0) {
					if((I1 +I2) >= 10){
						std::cin >> I3;
						while(I3 < 0 || I3 > 10)std::cin >> I3;
					}
					eval_Inputs(I1, I2, i);
					isBValue = 1;
				}
			}
			
		}
		isBValue = 0;
	}
	I3 += Qd[9].getScore();
	Qd[9].setScore(I3);
	for(unsigned int i = 0; i < 10;i++){
		totalScore += Qd[i].getScore();
	}
	std::cout << "Scores obtained in each quadrant:" << std::endl; 
	for(unsigned int i = 0; i < 10;i++)std::cout << Qd[i].getScore() << " ";
	std::cout << std::endl; 
	std::cout << "El Puntaje total es: " << totalScore << std::endl;
}
		
void Bowling_Game::addScore(int I1, int I2, int quad_N){
	int aS = 0, acV = 0;
	if(quad_N == 0)return;
	else if(quad_N == 1){
		if(Qd[0].getAccumVal() != 0){
			aS = Qd[0].getScore() + I1;
			acV = Qd[0].getAccumVal()-1;
			Qd[0].setAccumVal(acV);
			Qd[0].setScore(aS);
		}
		if(I1 != 10 && Qd[0].getAccumVal() != 0){
			aS += I2;
			acV = Qd[0].getAccumVal()-1;
			Qd[0].setAccumVal(acV);
			Qd[0].setScore(aS);
		}
		aS = 0;
	}
	else{
		for(int i = quad_N-1;i >= quad_N-2;i--){
			if(Qd[i].getAccumVal() != 0){
				aS = Qd[i].getScore() + I1;
				acV = Qd[i].getAccumVal()-1;
				Qd[i].setAccumVal(acV);
				Qd[i].setScore(aS);
			}
			if(I1 != 10 && Qd[i].getAccumVal() != 0){
				aS += I2;
				acV = Qd[i].getAccumVal()-1;
				Qd[i].setAccumVal(acV);
				Qd[i].setScore(aS);
			}
			aS = 0;
		}
		
	}
}

int Bowling_Game::eval_Inputs(int I1, int I2, int quad_N){
	Quadrant q1;
	addScore(I1, I2, quad_N);
	if(I1 == 10){
		q1.setScore(I1);
		q1.setAccumVal(2);
	}
	else if((I1+I2) == 10){
		q1.setScore(I1+I2);
		q1.setAccumVal(1);
	}
	else{
		q1.setScore(I1+I2);
		q1.setAccumVal(0);
	}
	Qd.push_back(q1);
}	
		