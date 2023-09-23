#pragma once

#include "../Constantes.h"
#include "../operators/interval/MOEADRandomSelection.h"
#include "../operators/interval/RandomSelection.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"
#include "../operators/interval/LLHSelectionOperator.h"
#include "../operators/interval/LLHRandomSelection.h"
#include "../operators/interval/LLHIndicatorSelection.h"

class DECISIONAID_LIB LLHSelectionBuilder : public GenericBuilder {
private:
	static LLHSelectionOperator* built(Requirements* req);
	LLHSelectionBuilder();

public:
	static LLHSelectionOperator* execute(Requirements* req);
	static LLHSelectionOperator* execute(const char configuration_file[]);
};
