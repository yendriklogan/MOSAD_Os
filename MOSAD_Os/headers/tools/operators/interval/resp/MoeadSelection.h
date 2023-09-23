#pragma once

#include "../interval/SelectionOperator.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB MoeadSelection: public SelectionOperator {
	protected:
		int* vector_neighborhood;

	public:
		virtual Solution execute(SolutionSet population);

		virtual void setNeighborhood(int* neighbors_in_order);

		virtual void initialize(Requirements* config);


};
