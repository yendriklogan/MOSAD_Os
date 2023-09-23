#pragma once

#include "COEImprovementOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COENonSearchImprovement : public COEImprovementOperator {
public:
	virtual void execute(Solution ind);
	virtual void initialize(Requirements* config);
};
