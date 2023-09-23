#pragma once

#include "Instance.h"
#include "../tools/data/Interval.h"
#include "../tools/Constantes.h"
#include "../problems/Problem.h"
#include <iostream>
#include <fstream>

#include "../solutions/SolutionSet.h"
#include "../preferences/outranking/OutrankingModel.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB PDA_DTLZ_Instance : public Instance {
private:
	int num_objs;
	int num_dv;

	Problem* om_prob;
	Instance* om_inst;

	SolutionSet* C1;
	SolutionSet* C2;
	SolutionSet* pop;

	Interval* Z_min;
	Interval* Z_max;

	OutrankingModel* om;

	char* readNextDataLine(ifstream in);
	void tokenize(char* line, int limit);

public:
	PDA_DTLZ_Instance(OutrankingModel* om, Interval* Z_min, Interval* Z_max, SolutionSet* C1, SolutionSet* C2, SolutionSet* pop);

	void loadInstance(const char path_file[]);

	int getNumObjectives();
	int getNumDecisionVariables();
	Problem* getProblem();
	Interval getLimits(int problem_obj);
	SolutionSet* getC1();
	SolutionSet* getC2();
	OutrankingModel* getOutrankingModel();

	DECISIONAID_LIB friend ostream& operator<<(ostream& os, PDA_DTLZ_Instance dt);

};

