#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../Operator.h"
#include "../../../solutions/Solution.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB NeighborhoodOperator : public Operator {
public:
	virtual ~NeighborhoodOperator() = 0;
	virtual Solution* execute(Solution* parent);
	virtual void initialize(Requirements* config);
};
