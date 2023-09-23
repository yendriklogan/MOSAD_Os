#pragma once

#include "Indicator.h"

#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB IGD : public Indicator {
	Interval* roi = NULL;

	public:
		IGD();	
		Interval execute(SolutionSet *refernceSet, SolutionSet *aproximateSet) override;		//normalized computation using a vector of values
		Interval minimaDistance(Solution s, SolutionSet* aproximateSet);
		Interval distanciaEuclideana(Solution s1, Solution s2);
};
