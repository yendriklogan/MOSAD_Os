#pragma once

#include "../interval/MoeadSelection.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEMoeadSelection: public MoeadSelection {
	protected:
		int sp;				//species being handled
		int S;				//number of species
		int** DV_ss;        //Input parameters [decision variables handled by species]
		int** OF_ss;        //Input parameters [objectives handled by species]
		int* vector_neighborhood;

	public:
		virtual Solution execute(SolutionSet population);

		virtual void setNeighborhood(int* neighbors_in_order);

		virtual void initialize(Requirements* config);

		virtual void setSpecies(int i);
		virtual void initSpeciesInfo(int S, int** DV_ss, int** OF_ss);


};
