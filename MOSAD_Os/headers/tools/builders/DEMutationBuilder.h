#pragma once

#include "../../tools/Constantes.h"
#include "../../tools/operators/interval/RandOneDEMutation.h"

#include "../../tools/Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB DEMutationBuilder {
private:
	static DEMutationOperator* built(Requirements* req);

	DEMutationBuilder();

public:
	static DEMutationOperator* execute(Requirements* req);
	static DEMutationOperator* execute(const char configuration_file[]);
};
