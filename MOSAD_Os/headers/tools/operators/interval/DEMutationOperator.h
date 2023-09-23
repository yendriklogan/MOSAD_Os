#pragma once

#include "../../Requirements.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB DEMutationOperator : public Operator {
public:
	virtual void execute(SolutionSet ind, Solution mutant);	
	virtual void initialize(Requirements* config);
};
