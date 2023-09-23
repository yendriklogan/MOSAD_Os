#pragma once

#include "../Constantes.h"
#include "../GenericBuilder.h"
//#include "../../problems/PSP_Fuzzy.h"
#include "../../problems/standard/pda/PDA_DTLZ.h"
#include "../../problems/standard/preference/PDTLZ1.h"
#include "../../problems/standard/preference/PDTLZ2.h"
#include "../../problems/standard/preference/PDTLZ3.h"
#include "../../problems/standard/preference/PDTLZ4.h"
#include "../../problems/standard/preference/PDTLZ5.h"
#include "../../problems/standard/preference/PDTLZ6.h"
#include "../../problems/standard/preference/PDTLZ7.h"
//#include "../../problems/Knapsack.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB ProblemBuilder : public GenericBuilder {
private:
	
	Requirements* config = NULL;

	static Problem* built(Requirements* config);
	Problem* built();
	ProblemBuilder();	

public:		
	static Problem* execute(Requirements* config);
	static Problem* execute(const char configuration_file[]);
};

