#ifndef QUA_H
#define QUA_H

#include <iostream>
#include <vector>

class Quadrant{
	public:
		//! Constructor.
		Quadrant();
		//! Destroyer.
		~Quadrant();
		void setScore(int sc);
		int getScore();
		void setAccumVal(int av);
		int getAccumVal();

	private:
		int score;
		int accum_val;
};

#endif