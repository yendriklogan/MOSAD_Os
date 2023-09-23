#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB UpdateMOEADNeighborhood : public Operator {
public:
	UpdateMOEADNeighborhood();
	virtual ~UpdateMOEADNeighborhood() = 0;
	virtual void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max, int evaluations);
	virtual void initialize(Requirements* config);
};

