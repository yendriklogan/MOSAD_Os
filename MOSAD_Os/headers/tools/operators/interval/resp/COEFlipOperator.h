#pragma once

#include "../../../../include/tools/operators/interval/COENeighborhoodOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEFlipOperator : public COENeighborhoodOperator {
	private:

	public:
		Solution* execute(Solution* parent) override;
		void initialize(Requirements* config) override;
};
