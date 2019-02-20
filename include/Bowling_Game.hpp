#ifndef SE_H
#define SE_H
#include "Quadrant.hpp"

class Bowling_Game{
	public:
		//! Constructor.
		Bowling_Game();
		//! Destroyer.
		~Bowling_Game();
		int setInput1(int I1);
		int getInput1();
		int setInput2(int I2);
		int getInput2();
		void setTotalScore(int TS);
		int getTotalScore();
		void startGame();
		void addScore(int I1, int I2, int quad_N);
		int eval_Inputs(int I1, int I2, int quad_N);
	private:
		int input1;
		int input2;
		std::vector<Quadrant> Qd;
		int totalScore;
};

#endif