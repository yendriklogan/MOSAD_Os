#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "../Operator.h"
#include "../../../metaheuristics/LowLevelHeuristicSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB LLHSelectionOperator : public Operator {
public:
	virtual ~LLHSelectionOperator()= 0;
	virtual int execute(LowLevelHeuristicSet *heuristics);
	virtual int execute(LowLevelHeuristicSet* heuristics, SolutionSet* P);
	virtual void initialize(Requirements* config);
};
