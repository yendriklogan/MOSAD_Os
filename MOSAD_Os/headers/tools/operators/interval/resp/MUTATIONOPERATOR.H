#pragma once

#include "../../RandomNumber.h"
#include "../../../problems/Problem.h"
#include "../../Requirements.h"
#include "../../Constantes.h"
#include "../Operator.h"
#include "../../../solutions/SolutionSet.h"

#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB MutationOperator : public Operator {
public:
	virtual ~MutationOperator();
	virtual void execute(Solution ind);	
	virtual void initialize(Requirements* config);
};
