#pragma once

#include "../Constantes.h"
#include "../../preferences/outranking/FDEA_Outranking.h"
#include "../Requirements.h"
#include "../GenericBuilder.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB OutrankingModelBuilder : public GenericBuilder {
private:
	static OutrankingModel* built(Requirements* req);

	OutrankingModelBuilder();

public:
	static OutrankingModel* execute(Requirements* req);
	static OutrankingModel* execute(const char configuration_file[]);
};
