#pragma once

#include "WeightVectorModel.h"
#include "../../Combinations.h"
#include "../../GreaterThanPolinomyals.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB CAModel : public WeightVectorModel {
	int N = 0;		//Input NumberOfVectors
	int M = 0;		//Input NumberOfObjectives
public:
	CAModel();
	void initialize(Requirements* req) override;
	Interval** execute() override;
};

