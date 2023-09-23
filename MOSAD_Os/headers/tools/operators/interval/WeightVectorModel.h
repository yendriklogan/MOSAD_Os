#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../operators/Operator.h"
#include "../../Constantes.h"
#include "../../data/Interval.h"
#include "../../Requirements.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB WeightVectorModel : public Operator {

protected:
	int N = 0;		//Input NumberOfVectors
	int M = 0;		//Input NumberOfObjectives
public:
	WeightVectorModel();
	virtual ~WeightVectorModel() = 0;
	virtual void initialize(Requirements* req); 
	virtual Interval** execute();
};
