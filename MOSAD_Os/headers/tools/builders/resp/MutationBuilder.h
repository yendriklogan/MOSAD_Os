#pragma once

#include "../Constantes.h"
#include "../operators/interval/PolynomialMutation.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB MutationBuilder : public GenericBuilder {
private:
	static MutationOperator* built(Requirements* req);

	MutationBuilder();

public:
	static MutationOperator* execute(Requirements* req);
	static MutationOperator* execute(const char configuration_file[]);
};
