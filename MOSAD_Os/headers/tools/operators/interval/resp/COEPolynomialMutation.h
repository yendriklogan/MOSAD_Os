#pragma once

#include "COEMutationOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEPolynomialMutation : public COEMutationOperator {
private:
    double mutationProbability_;    //Input [PolynomialMutation-probability] probability of mutating
    double Eta_m;                   //Input [PolynomialMutation-Eta] 

public:
	void execute(Solution ind) override;
    void initialize(Requirements* config) override;
};
