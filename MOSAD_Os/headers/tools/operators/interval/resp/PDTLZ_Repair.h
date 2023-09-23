#pragma once

#include "RepairOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB PDTLZ_Repair : public RepairOperator {
public:
	virtual void execute(Solution ind);
	virtual void initialize(Requirements* config);
};
