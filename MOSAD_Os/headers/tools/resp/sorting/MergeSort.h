#pragma once

#include "../../../WindowsRequirements.h"


class DECISIONAID_LIB MergeSort {
	protected:
		int* indexes_;
		double* values_;
		int size;

		void merge(int* ind, double* a, int left, int mid, int right);
		void sort(int* ind, double* a, int begin, int end);

	public:
		void initialize(int *indexes, double *values, int);
		
		void execute();
};
