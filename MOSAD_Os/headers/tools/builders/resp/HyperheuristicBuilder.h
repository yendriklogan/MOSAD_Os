#pragma once

#include "../../tools/Constantes.h"
#include "../../metaheuristics/Algorithm.h"
#include "../../hyperheuristics/Hyperheuristic.h"
#include "../../hyperheuristics/MaOLS_HH_UP.h"
#include "../../tools/builders/ProblemBuilder.h"
#include "../../tools/Parameters.h"
#include "../GenericBuilder.h"

#include "../../tools/Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB HyperheuristicBuilder : public GenericBuilder {
private:
	static Hyperheuristic* built(Requirements* config);

	HyperheuristicBuilder();

public:
	static Hyperheuristic* execute(Requirements* config);
	static Hyperheuristic* execute(const char configuration_file[]);
};
