#pragma once

#include "RepairOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB DERepairV2 : public RepairOperator {
private:
	Interval repairing(Interval value, Interval lowerBound, Interval upperBound);
public:
	virtual void execute(Solution ind);
	virtual void initialize(Requirements* config);

};
