#pragma once

#include "../Constantes.h"
//#include "../operators/interval/SBXCrossover.h"
#include "../operators/interval/BinomialCrossover.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB CrossoverBuilder : public GenericBuilder {
private:
	static CrossoverOperator* built(Requirements* req);

	CrossoverBuilder();

public:
	static CrossoverOperator* execute(Requirements* req);
	static CrossoverOperator* execute(const char configuration_file[]);
};
