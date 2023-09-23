#pragma once

#include "Indicator.h"

#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB ROI_EuclideanTchebycheff : public Indicator {
	Interval* roi = NULL;

	public:
		ROI_EuclideanTchebycheff();
		void reset();
		void setProblem(Problem* p);
		void setROI(Interval* roi);
		void execute(SolutionSet* set) override;								//computation using a set
		void execute(Solution* sol) override;									//computation using a solution
		void execute(Interval* sol, int m) override;									//computation using a vector of values
		void execute(SolutionSet* set, Interval* min, Interval* max) override;	//normalized computation using a set
		void execute(Solution* sol, Interval* min, Interval* max) override;		//normalized computation using a solution
		void execute(Interval* sol, int m, Interval* min, Interval* max) override;
		virtual Interval execute(SolutionSet* set1, SolutionSet* set2) override;		//normalized computation using a vector of values
};
