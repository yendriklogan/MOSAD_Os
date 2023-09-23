#pragma once

#include "../tools/data/Interval.h"
#include "../solutions/SolutionSet.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB DominanceComparator {
	public:
		virtual ~DominanceComparator() = 0;
		virtual int compare(Solution s1, Solution s2);
		virtual int compare(Solution s1, Interval s2[]);
		virtual int compare(Interval s1[], Interval s2[], int optimization[], int num_objs);
		virtual bool compareSet(Solution s1, SolutionSet set);
		virtual bool compareSet(Solution s1, SolutionSet set, int dominance[]);
		virtual bool compareSet(Interval s1[], SolutionSet set, int dominance[]);

		virtual int compare_constrained(Solution s1, Solution s2);
		virtual int compare_constrained(Solution s1, Interval s2[], Interval ocv2, Interval nvc2); //[ocv] - overall constrained violation, [nvc] - number of violated constraints
		virtual int compare_constrained(Interval s1[], Interval ocv1, Interval nvc1, Interval s2[], Interval ocv2, Interval nvc2, int optimization[], int num_objs);
		virtual bool compareSet_constrained(Solution s1, SolutionSet set);
		virtual bool compareSet_constrained(Solution s1, SolutionSet set, int dominance[]);
		virtual bool compareSet_constrained(Interval s[], Interval ocv, Interval nvc, SolutionSet set, int dominance[]);
};
