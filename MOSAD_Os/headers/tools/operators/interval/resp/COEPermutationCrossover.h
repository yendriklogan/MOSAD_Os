#pragma once

#include "COECrossoverOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEPermutationCrossover : public COECrossoverOperator {
	private:
		const double EPS = 1.0e-14;

		//Variables locales a funciones estaticas
		Solution y[4];		//usada en [execute]
		int* h1_missing;		//usada en [execute]
		int* h2_missing;		//usada en [execute]
		bool local_ini;		//usada en [execute] para indicar si c ya fue inicializada por primera vez con problema [p] (y no consumir memoria)

	public:
		void execute(SolutionSet parents, SolutionSet children) override;
		void initialize(Requirements* config) override;
};