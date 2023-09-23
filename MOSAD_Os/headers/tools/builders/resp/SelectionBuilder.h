#pragma once

#include "../Constantes.h"
#include "../operators/interval/MOEADRandomSelection.h"
#include "../operators/interval/RandomSelection.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB SelectionBuilder : public GenericBuilder {
private:
	static SelectionOperator* built(Requirements* req);

	SelectionBuilder();

public:
	static SelectionOperator* execute(Requirements* req);
	static SelectionOperator* execute(const char configuration_file[]);
};
