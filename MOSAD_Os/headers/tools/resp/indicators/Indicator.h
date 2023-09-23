#pragma once

#include "../../problems/Problem.h"
#include "../../solutions/SolutionSet.h"
#include "../Parameters.h"

#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB Indicator {
	protected:
		Problem* prob_ = NULL;
		Parameters ind_val;			//stores de values of the indicator
		Parameters ind_sol;			//stores de solution associated to the values

	public:
		Indicator();
		virtual void execute(SolutionSet* set);		//computation using a set
		virtual void execute(Solution* sol);		//computation using a solution
		virtual void execute(Interval* sol, int m);		//computation using a vector of values
		virtual void execute(SolutionSet* set, Interval* min, Interval* max);	//normalized computation using a set
		virtual void execute(Solution* sol, Interval* min, Interval* max);		//normalized computation using a solution
		virtual void execute(Interval* sol, int m, Interval* min, Interval* max);		//normalized computation using a vector of values
		virtual Interval execute(SolutionSet *set1, SolutionSet *set2);
		virtual void initialize(Requirements* config);
};
