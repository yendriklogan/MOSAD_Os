#pragma once

#include "../interval/LLHSelectionOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB LLHRandomSelection : public LLHSelectionOperator {
public:
	int execute(LowLevelHeuristicSet *heuristics) override;
	void initialize(Requirements* config) override;
};
