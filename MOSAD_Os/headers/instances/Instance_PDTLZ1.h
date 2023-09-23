#pragma once

#include "Instance.h"
#include "../tools/data/Interval.h"
#include "../tools/Constantes.h"
#include <iostream>
#include <fstream>

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Instance_PDTLZ1 : public Instance {

	private:
		char* readNextDataLine(ifstream in);
		void tokenize(char* line, int limit);

	public:
		Instance_PDTLZ1();

		void loadInstance(const char path_file[]);

		int getNumObjectives();
		int getNumDecisionVariables();

		int getNumDMs();

		
		Interval** getWeights_DMs();
		Interval** getVetos_DMs();
		Interval* getLambdas_DMs();
		Interval** getBestCompromises();
		Interval** getInitialSolutions();
		Interval** getROI();
		int getNumInitialSolutions();
		int getNumBestCompromises();
		int getSizeROI();

		DECISIONAID_LIB friend ostream& operator<<(ostream& os, Instance_PDTLZ1 dt);

};
