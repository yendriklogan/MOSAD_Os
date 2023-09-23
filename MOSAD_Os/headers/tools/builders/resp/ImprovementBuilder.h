#pragma once

#include "../Constantes.h"
#include "../operators/interval/NonSearchImprovement.h"
#include "../operators/interval/ImprovementHassanien.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB ImprovementBuilder : public GenericBuilder {
private:
	static ImprovementOperator* built(Requirements* req);

	ImprovementBuilder();

public:
	static ImprovementOperator* execute(Requirements* req);
	static ImprovementOperator* execute(const char configuration_file[]);
};
