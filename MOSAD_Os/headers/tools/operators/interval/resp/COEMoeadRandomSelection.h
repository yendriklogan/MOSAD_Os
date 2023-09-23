#pragma once

#include "../interval/COEMoeadSelection.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEMoeadRandomSelection : public COEMoeadSelection {
public:
	Solution execute(SolutionSet population) override;

	void setNeighborhood(int* neighbors_in_order) override;

	void initialize(Requirements* config) override;
};
