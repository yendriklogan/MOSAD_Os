#pragma once

#include "CrossoverOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB BinomialCrossover : public CrossoverOperator {
	private:
		const double EPS = 1.0e-14;

		double crossoverRate;
		int dimensionOfDiference;

		//Variables locales a funciones estaticas
		Solution c[2];		//usada en [execute]

	public:
		void execute(SolutionSet parents, SolutionSet children) override;
		void initialize(Requirements* config) override;
};