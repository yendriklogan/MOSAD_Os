#pragma once

#include "../tools/data/Interval.h"
#include "../problems/Problem.h"
#include "../solutions/SolutionSet.h"

#include "../tools/Constantes.h"
#include "../tools/Dominance.h"

#include "../../WindowsRequirements.h"


using namespace std;

class DECISIONAID_LIB FastNonDominatedSort {
	private:
		SolutionSet set;

		//variables locales a [execute]
		SolutionSet front;
		SolutionSet* fronts = NULL;
		int* F = NULL;
		int cF = 0;
		int* H = NULL;
		int cH = 0;
		int** S = NULL;
		int* cS = NULL;
		int* n = NULL;
		int* sol_front = NULL;		//stores the fronts were the solution was assigned after sorting in execute

	public:
		FastNonDominatedSort();
		FastNonDominatedSort(SolutionSet s);
		void initialize(SolutionSet s);
		SolutionSet* execute();
		void changeSet(SolutionSet s);
		int* getSolutionIndexFront();
};
