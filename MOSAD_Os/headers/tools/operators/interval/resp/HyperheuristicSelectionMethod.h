#pragma once


#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB HyperheuristicSelectionMethod: public operator {
public:
	Solution execute(SolutionSet population) override;

	void initialize(Requirements* config) override;
};