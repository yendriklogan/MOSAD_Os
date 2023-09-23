#pragma once

#include "CrossoverOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB SBXCrossover : public CrossoverOperator {
	private:
		const double EPS = 1.0e-14;

		double crossoverProbability_;
		double Eta_c;

		//Variables locales a funciones estaticas
		Solution c[2];		//usada en [execute]
		Solution y1, y2;	//usada en [execute]
		bool local_ini;		//usada en [execute] para indicar si c ya fue inicializada por primera vez con problema [p] (y no consumir memoria)

	public:
		void execute(SolutionSet parents, SolutionSet children) override;
		void initialize(Requirements* config) override;
};