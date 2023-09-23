#pragma once

#include "COERepairOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COENonRepair : public COERepairOperator {
	public:
		virtual void execute(Solution ind);
		virtual void initialize(Requirements* config);
};
