#pragma once

#include "../Constantes.h"
#include "../operators/interval/FlipOperator.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB NeighborhoodBuilder : public GenericBuilder {
private:
	static NeighborhoodOperator* built(Requirements* req);

	NeighborhoodBuilder();

public:
	static NeighborhoodOperator* execute(Requirements* req);
	static NeighborhoodOperator* execute(const char configuration_file[]);
};
