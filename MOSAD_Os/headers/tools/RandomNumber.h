#pragma once

#include "data/Interval.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB RandomNumber {
	private:
		static RandomNumber* instance;
		unsigned long seed;

		RandomNumber();


	public:
		static RandomNumber* getInstance();
		void setSeed();
		void setSeed(unsigned long seed);
		unsigned long getSeed();
		int nextInt(int N);				//genera un número aleatorio entre 0 y N (incluyendo N)
		double nextDouble();
		double nextDouble(double N);
		//static Interval nextInterval(Interval N);
};
