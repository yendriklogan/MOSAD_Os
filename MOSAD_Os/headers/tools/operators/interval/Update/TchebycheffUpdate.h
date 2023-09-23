#pragma once

#include "../UpdateMOEADNeighborhood.h"

#include "../../../../../WindowsRequirements.h"

class DECISIONAID_LIB TchebycheffUpdate : public UpdateMOEADNeighborhood {
	int T = -1;		//Input parameter

public:
	TchebycheffUpdate();
	void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max, int evaluations);
	Interval g_te(Solution* x, Interval moead_weights[], Interval z_min[], Interval z_max[]);
	void initialize(Requirements* config) override;
};
