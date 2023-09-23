#pragma once

#include "../../../../preferences/operators/DTLZ_NSS.h"
#include "../../../operators/interval/UpdateMOEADNeighborhood.h"
#include "../../../builders/OutrankingModelBuilder.h"
#include "../../../../../WindowsRequirements.h"

class DECISIONAID_LIB TchebycheffOutrankingUpdate : public UpdateMOEADNeighborhood {
	int T = -1;						//Input parameter, the number of neighborhood functions
	int N = -1;						//Input parameter, the number of weight vector (equivalent to the numer of DMs [because each WV associates a DM])
	int variante_ = -1;				//Input parameter
	int SelectivePressureThreshold = -1; //Input parameter //threshold to apply selective pressure using outrank. The threshold value "v" means that every "v" evaluations the outranking selective pressure is used

	Requirements** dms_config = NULL;	//Input parameter, contains the information that defines each DM
	DTLZ_NSS** dms_nss = NULL;			//Input Parameter
	OutrankingModel** dms = NULL;		//Input parameter, the vector of DMs associated with each weight vector


public:
	TchebycheffOutrankingUpdate();
	void execute(int i, SolutionSet* children, Interval** weightVectors, int** initial_B, SolutionSet* B, Interval* Z_min, Interval* Z_max, int evaluations) override;
	Interval g_te(Solution* x, Interval moead_weights[], Interval z_min[], Interval z_max[]);
	void initialize(Requirements* config) override;

	void update_dms(Requirements* config);			//contains a file listing the [path files] for each DM
	void update_dm(int i, const char file[]);	//contains a [path file] with the parameter information of the DM
};


