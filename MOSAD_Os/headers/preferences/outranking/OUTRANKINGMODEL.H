#pragma once

#include "../../tools/data/Interval.h"
#include "../../tools/Parameters.h"
#include "../../problems/Problem.h"
#include "../../solutions/Solution.h"
#include "../../tools/Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB OutrankingModel {
	protected:
		Problem* problem_;
		Parameters* params_;

	public:
		OutrankingModel();
		virtual ~OutrankingModel() = 0;
		virtual void initialize(Requirements* config);

		OutrankingModel(Problem* problem_, Parameters* params);

		Problem* getProblem();
		Instance* getInstance();
		virtual int outranking(Solution* o1, Solution* o2);
		virtual int outranking(Interval o1[], Interval o2[]);
		virtual Interval getLastCredibilityIndex_XY();
		virtual Interval getLastCredibilityIndex_YX();

		virtual Interval getCredibilityThreshold();

		virtual Parameters* getParameters();
		virtual void setWeights(Interval* weights);
		void setProblem(Problem* problem);
};
