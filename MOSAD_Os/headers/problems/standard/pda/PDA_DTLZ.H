#pragma once

#include "../../../tools/data/Interval.h"
#include "../../../solutions/Solution.h"
#include "../../../solutions/SolutionSet.h"
#include "../../../instances/PDA_DTLZ_Instance.h"
#include "../../../tools/builders/OutrankingModelBuilder.h"
#include "../../../tools/builders/ProblemBuilder.h"

#include "../../../../WindowsRequirements.h"

#define M_PIl  3.141592653589793238462643383279502884L

class DECISIONAID_LIB PDA_DTLZ : public Problem {
	Parameters* param_;

	PDTLZ* dtlz;			//input: DTLZ problem over which the PDA will estimate the Outranking Model parameters

	int size;				//input: size of the solution set

	SolutionSet* RF;		//input: el conjunto de solutiones de tamaño n
	int* R1;				//input: vector de tamaño n que indica con un 1, si la solucion i pertenece a la clase C1, y con un 0 en caso contrario
	int* R2;				//input: vector de tamaño n que indica con un 2, si la solucion i pertenece a la clase C2, y con un 0 en caso contrario

	int* p_R1;				//PROCESO: clase predecida		
	int* p_R2;				//PROCESO: clase predecida

	Interval* RA1;			//proceso: guardaran los valores estimados para las acciones representativas de la clase C1
	Interval* RA2;			//proceso: guardaran los valores estimados para las acciones representativas de la clase C2


public:
	PDA_DTLZ();
	void initialize(Requirements* config) override;

	void evaluate(Solution* s) override;
	void evaluateConstraints(Solution* s) override;
	Solution generateRandomSolution();
};

