#pragma once

#include "../Constantes.h"
#include "../operators/interval/CAModel.h"
//#include "../operators/interval/NUMSModel.h"
//#include "../operators/interval/DasDenisWeightGenerationModel.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB WeightVectorBuilder : public GenericBuilder {
private:
	static WeightVectorModel* built(Requirements* req);

	WeightVectorBuilder();

public:
	static WeightVectorModel* execute(Requirements* req);
	static WeightVectorModel* execute(const char configuration_file[]);
};
