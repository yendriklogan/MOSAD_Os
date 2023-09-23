#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "RepairOperator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COERepairOperator : public RepairOperator {
	protected:
		int sp;				//species being handled
		int S;				//number of species
		int** DV_ss;        //Input parameters [decision variables handled by species]
		int** OF_ss;        //Input parameters [objectives handled by species]

	public:
		virtual ~COERepairOperator() = 0;
		virtual void execute(Solution ind);
		virtual void initialize(Requirements* config);
		virtual void setSpecies(int i);
		virtual void initSpeciesInfo(int S, int** DV_ss, int** OF_ss);
};
