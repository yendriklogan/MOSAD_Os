#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "UpdateMOEADNeighborhood.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEUpdateMOEADNeighborhood : public UpdateMOEADNeighborhood {
	protected:
		int sp;				//species being handled
		int S;				//number of species
		int** DV_ss;        //Input parameters [decision variables handled by species]
		int** OF_ss;        //Input parameters [objectives handled by species]
		int* WV_ss;			//Input parameters [weight vector handled by species]
	public:
		COEUpdateMOEADNeighborhood();
		virtual ~COEUpdateMOEADNeighborhood() = 0;
		virtual void setSpecies(int i);
		virtual void initSpeciesInfo(int S, int** DV_ss, int** OF_ss, int* WV_ss);
		virtual void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max, int evaluations);
		virtual void initialize(Requirements* config);
};

