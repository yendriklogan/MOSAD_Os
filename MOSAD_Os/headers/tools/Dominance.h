#pragma once

#include "../tools/data/Interval.h"
#include "../solutions/Solution.h"
#include "../solutions/SolutionSet.h"
#include "DominanceComparator.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Dominance : public DominanceComparator {
protected:


public:
	Dominance();
	int compare(Solution s1, Solution s2) override;
	int compare(Solution s1, Interval s2[]) override;
	int compare(Interval s1[], Interval s2[], int optimization[], int num_objs) override;
	bool compareSet(Solution s1, SolutionSet set) override;
	bool compareSet(Solution s1, SolutionSet set, int dominance[]) override;
	bool compareSet(Interval s1[], SolutionSet set, int dominance[]) override;
	
	//managing feasibility by constraints
	int compare_constrained(Solution s1, Solution s2) override;
	int compare_constrained(Solution s1, Interval s2[], Interval ocv2, Interval nvc2) override;
	int compare_constrained(Interval s1[], Interval ocv1, Interval nvc1, Interval s2[], Interval ocv2, Interval nvc2, int optimization[], int num_objs) override;
	bool compareSet_constrained(Solution s1, SolutionSet set) override;
	bool compareSet_constrained(Solution s1, SolutionSet set, int dominance[]) override;
	bool compareSet_constrained(Interval s1[], Interval ocv1, Interval nvc1, SolutionSet set, int dominance[]) override;
};
