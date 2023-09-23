#pragma once

#include "../../../../include/tools/operators/interval/NeighborhoodOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB FlipOperator : public NeighborhoodOperator {
	private:

	public:
		Solution* execute(Solution* parent) override;
		void initialize(Requirements* config) override;
};
