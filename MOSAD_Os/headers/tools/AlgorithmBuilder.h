#pragma once

#include "../tools/Constantes.h"
#include "../metaheuristics/Algorithm.h"
#include "../metaheuristics/COMOEAD_Interactive.h"
#include "../metaheuristics/SimulatedAnnealing.h"
#include "../metaheuristics/MOEAD_NUMS.h"
#include "../metaheuristics/MOEAD_Hassanien.h"
#include "../metaheuristics/MOEAD_M2M.h"
#include "../metaheuristics/FDEA_I.h"
#include "../metaheuristics/FDEA_II.h"
#include "../metaheuristics/FDEA_II_2.h"
#include "../metaheuristics/FDEA_II_O.h"
#include "../metaheuristics/FDEA_II_O_2.h"
#include "../metaheuristics/MOEAD.h"
#include "../metaheuristics/MOEAD_O.h"
#include "../metaheuristics/MOSA.h"
#include "../metaheuristics/MOSAD.h"
#include "../metaheuristics/MOSAD_O.h"
#include "../metaheuristics/MOSAD_DE.h"
#include "../metaheuristics/MOSAD_DE_I.h"
#include "../tools/builders/ProblemBuilder.h"
#include "../tools/Parameters.h"
#include "GenericBuilder.h"

#include "../tools/Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB AlgorithmBuilder : public GenericBuilder {
private:
	static Algorithm* built(Requirements* config);

	AlgorithmBuilder();

public:
	static Algorithm* execute(Requirements* config);
	static Algorithm* execute(const char configuration_file[]);
};
