#pragma once

#include "RepairOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB DERepairV3 : public RepairOperator {
private:
	Parameters par;
	double lowerBound;
	double upperBound;
	Interval repairing(Interval value, Interval lowerBound, Interval upperBound);
public:
	virtual void execute(Solution ind);
	virtual void initialize(Requirements* config);

};
