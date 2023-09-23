#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "CrossoverOperator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COECrossoverOperator : public CrossoverOperator {
	protected:
		int sp;				//species being handled
		int S;				//number of species
		int** DV_ss;        //Input parameters [decision variables handled by species]
		int** OF_ss;        //Input parameters [objectives handled by species]

	public:
		virtual ~COECrossoverOperator() = 0;
		virtual void setSpecies(int i);
		virtual void initSpeciesInfo(int S, int** DV_ss, int** OF_ss);
		virtual void execute(SolutionSet parents, SolutionSet children);
		virtual void initialize(Requirements* config);
};
