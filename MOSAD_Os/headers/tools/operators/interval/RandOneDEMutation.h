#pragma once

#include "DEMutationOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB RandOneDEMutation : public DEMutationOperator {
private:
    double scaleFactor;

public:
	void execute(SolutionSet ind, Solution mutant) override;
    void initialize(Requirements* config) override;
    Interval repairing(Interval value, Interval lowerBound, Interval upperBound);
};

