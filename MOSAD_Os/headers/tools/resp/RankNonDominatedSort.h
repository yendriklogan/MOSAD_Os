#pragma once

#include "../tools/data/Interval.h"
#include "../problems/Problem.h"
#include "../solutions/SolutionSet.h"

#include "../tools/Constantes.h"
#include "../tools/Dominance.h"
#include "../tools/sorting/MergeSort.h"

#include "../../WindowsRequirements.h"


using namespace std;

class DECISIONAID_LIB RankNonDominatedSort {
	private:
		SolutionSet set;

		//variables locales a [execute]
		SolutionSet* front;
		//SolutionSet* fronts = NULL;
		double** objs = NULL;
		int** order = NULL;

		int* sols = NULL;

		int N = 0;
		int M = 0;

	public:
		RankNonDominatedSort();
		RankNonDominatedSort(SolutionSet s);
		void initialize(SolutionSet s);
		SolutionSet* execute();
		SolutionSet* execute_jensen();
		void changeSet(SolutionSet s);
};
