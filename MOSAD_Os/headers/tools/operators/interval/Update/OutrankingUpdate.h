#pragma once



#include "../UpdateMOEADNeighborhood.h"
#include "../../../../preferences/operators/DTLZ_NSS.h"
#include "../../../../../WindowsRequirements.h"

class DECISIONAID_LIB OutrankingUpdate : public UpdateMOEADNeighborhood {
private:
	int T;					//Input parameter
	DTLZ_NSS* nss;			//Input parameter
	OutrankingModel* om;	//Input parameter
	int variant;			//Input parameter

	bool satisfyTchebycheff(Solution* x, Solution* y, Interval moead_weights[], Interval z_min[], Interval z_max[]);
	bool satisfyOutranking(int var, Solution* y, Solution* x, Interval moead_weights[], Interval Z_min[], Interval Z_max[]);
	Interval g_te(Solution* x, Interval moead_weights[], Interval z_min[], Interval z_max[]);

public:
	OutrankingUpdate();
	void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max);
	

	

};

