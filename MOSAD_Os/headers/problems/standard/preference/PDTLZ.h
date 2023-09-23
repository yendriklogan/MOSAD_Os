#pragma once

#include "../../../tools/RandomNumber.h"
#include "../../../tools/Constantes.h"
#include "../../../tools/data/Interval.h"
#include "../../../solutions/Solution.h"
#include "../../../solutions/SolutionSet.h"
#include "../../Problem.h"
#include "../../../instances/Instance_PDTLZ1.h"
#include "../../../tools/Requirements.h"
#include "../../../../WindowsRequirements.h"

#define M_PIl  3.141592653589793238462643383279502884L

class DECISIONAID_LIB PDTLZ : public Problem {
protected:
	double ZERO = 1E-08;
	Instance_PDTLZ1* inst = NULL;
	Parameters par;
	int dm = -1;

public:
	PDTLZ();
	virtual ~PDTLZ() = 0;

	void initialize(Requirements* config) override;

	PDTLZ(Instance_PDTLZ1* inst, int dm);

	virtual double g(Solution* s);

	
	Instance* getInstance() override;
	int getDM();

	virtual void evaluate(Solution* s);
	virtual void evaluateConstraints(Solution* s);

	Solution generateRandomSolution() override;
	SolutionSet generateFromSolutionSet(Interval** solutions, int num_sol) override;
	Solution generateExistingSolution(Interval* solucion);
};

