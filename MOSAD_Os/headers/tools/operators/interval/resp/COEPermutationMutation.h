#pragma once

#include "COEMutationOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEPermutationMutation : public COEMutationOperator {
private:
    double mutationProbability_;    //Input [PolynomialMutation-probability] probability of mutating

public:
	void execute(Solution ind) override;
    void initialize(Requirements* config) override;
};
