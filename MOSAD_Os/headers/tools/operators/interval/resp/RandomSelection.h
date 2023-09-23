#pragma once

#include "../interval/MoeadSelection.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB RandomSelection : public SelectionOperator {
public:
	Solution execute(SolutionSet population) override;
	void initialize(Requirements* config) override;
};
