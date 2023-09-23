#pragma once

#include "../../../WindowsRequirements.h"
#include "../../tools/RandomNumber.h"

class DECISIONAID_LIB QuickSort {
	protected:
		int* indexes_;
		double* values_;
		int size;

		bool rnd_pivot;
		RandomNumber* rnd;

		int partition(int* ind, double* a, int start, int end);
		void sort(int* ind, double* a, int start, int end);

	public:
		void initialize(int *indexes, double *values, int, bool rnd_pivot = false);
		
		void execute();
};
