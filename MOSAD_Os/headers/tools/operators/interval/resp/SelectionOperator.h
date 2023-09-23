#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB SelectionOperator : public Operator {
public:
	virtual ~SelectionOperator()= 0;
	virtual Solution execute(SolutionSet population);
	virtual void initialize(Requirements* config);
};
