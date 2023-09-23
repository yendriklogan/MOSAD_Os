#pragma once

#include "../interval/LLHSelectionOperator.h"
#include "../../Dominance.h"
#include "../../indicators/Indicator.h"
#include "../../builders/IndicatorBuilder.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB LLHIndicatorSelection : public LLHSelectionOperator {
public:

	Indicator* indicator;
	int execute(LowLevelHeuristicSet* heuristics, SolutionSet* P) override;
	void initialize(Requirements* config) override;
	Interval sumaDominancia(SolutionSet* set1, SolutionSet* set2);
	double pcArea(SolutionSet* set1);
	double areaSol(Solution s);
	Interval min(Interval op1, Interval op2);
};