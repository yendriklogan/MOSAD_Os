#pragma once

#include "../tools/data/Interval.h"
#include "../solutions/SolutionSet.h"

#include "../tools/Constantes.h"
#include "../problems/Problem.h"


#include "../../WindowsRequirements.h"


using namespace std;

class DECISIONAID_LIB CrowdingDistance {
	private:

	protected:
		int* set_ordered_by_CD;
		Interval* crowding_distance;
		SolutionSet set;

	public:
		CrowdingDistance();
		CrowdingDistance(SolutionSet s);
		void initialize(SolutionSet s);
		void CrowdingDistanceAssignment();
		void order_by_CD();
		SolutionSet getBestKByCD(int K);
};
