#pragma once

#include "../UpdateMOEADNeighborhood.h"

#include "../../../../../WindowsRequirements.h"

class DECISIONAID_LIB TchebycheffNUMS : public UpdateMOEADNeighborhood {
	//based on (Li et al., 2018-Integration of Preferences on Decomposition), Equation (14)

	int T = 0;		//Input parameter
	double* zr = NULL; //Input parameter DM Aspiration Level (BY NOW ONLY INTRODUCED BY function)
	Interval rho = 1e-06;	//Value used in the update process

public:
	TchebycheffNUMS();
	void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max, int evaluations);
	Interval g_te(Solution* x, Interval moead_weights[], Interval z_min[], Interval z_max[]);
	void initialize(Requirements* config) override;
	void setAspirationLevel(double* zr);
};
