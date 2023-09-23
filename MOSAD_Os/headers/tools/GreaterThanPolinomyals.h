#pragma once

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB GreaterThanPolinomyals {
	private:

	public:
		int BASE;
		double PROPORCION;

		GreaterThanPolinomyals();
		GreaterThanPolinomyals(int b, double p);

		void InverseGTP(long long alpha, int m, long vector[]);
		void getDiophantineEquation(long long alpha, int m, double pf[]);
		
};
