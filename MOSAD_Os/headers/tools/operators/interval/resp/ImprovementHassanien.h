#pragma once


#include "../../../tools/Dominance.h"
#include "../interval/ImprovementOperator.h"
#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB ImprovementHassanien : public ImprovementOperator {
	int mejoras = -1;

public:
	ImprovementHassanien();
	void execute(Solution ind);
	void execute(SolutionSet* parents, SolutionSet* child);
	double** rsim_intervals(int n, SolutionSet* padres, SolutionSet* mutaciones);
	void initialize(Requirements* config) override;
};

