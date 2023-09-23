#pragma once

#include "ImprovementOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB NonSearchImprovement : public ImprovementOperator {
public:
	virtual void execute(Solution ind);
	virtual void initialize(Requirements* config);
};
