#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "NeighborhoodOperator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COENeighborhoodOperator : public NeighborhoodOperator {
	protected:
		int sp;				//species being handled
		int S;				//number of species
		int** DV_ss;        //Input parameters [decision variables handled by species]
		int** OF_ss;        //Input parameters [objectives handled by species]

	public:
		virtual ~COENeighborhoodOperator() = 0;
		virtual void setSpecies(int i);
		virtual void initSpeciesInfo(int S, int** DV_ss, int** OF_ss);
		virtual Solution* execute(Solution* parent);
		virtual void initialize(Requirements* config);
};
