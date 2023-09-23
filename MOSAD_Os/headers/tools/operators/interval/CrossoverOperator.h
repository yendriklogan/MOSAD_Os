#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB CrossoverOperator : public Operator {
	public:
		virtual ~CrossoverOperator() = 0;
		virtual void execute(SolutionSet parents, SolutionSet children);
		virtual void initialize(Requirements* config);
};
