#pragma once

#include "../../../tools/RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB ImprovementOperator : public Operator {
public:
	virtual ~ImprovementOperator() = 0;
	virtual void execute(Solution ind);
	virtual void execute(SolutionSet* parents, SolutionSet* children);
	virtual void initialize(Requirements* config);
};
