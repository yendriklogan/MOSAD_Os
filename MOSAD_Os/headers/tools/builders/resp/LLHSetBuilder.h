#pragma once

#include "../Constantes.h"
#include "../GenericBuilder.h"
#include "../../metaheuristics/LowLevelHeuristicSet.h"
#include "../../metaheuristics/Algorithm.h"
#include "../../tools/AlgorithmBuilder.h"
#include "../Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB LLHSetBuilder : public GenericBuilder {
private:
	
	Requirements* config = NULL;

	static LowLevelHeuristicSet* built(Requirements* config);
	LowLevelHeuristicSet* built();
	LLHSetBuilder();

public:		
	static LowLevelHeuristicSet* execute(Requirements* config);
	static LowLevelHeuristicSet* execute(const char configuration_file[]);
};

