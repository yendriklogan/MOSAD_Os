#pragma once

#include "../interval/MoeadSelection.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB MoeadRandomSelection : public MoeadSelection {
public:
	Solution execute(SolutionSet population) override;

	void setNeighborhood(int* neighbors_in_order) override;

	void initialize(Requirements* config) override;
};
