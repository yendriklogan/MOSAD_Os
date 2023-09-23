#pragma once

#include "../Constantes.h"
#include "../operators/interval/Update/TchebycheffNUMS.h"
#include "../operators/interval/Update/TchebycheffUpdate.h"
#include "../operators/interval/Update/TchebycheffOutrankingUpdate.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB UpdateBuilder : public GenericBuilder {
private:
	static UpdateMOEADNeighborhood* built(Requirements* req);

	UpdateBuilder();

public:
	static UpdateMOEADNeighborhood* execute(Requirements* req);
	static UpdateMOEADNeighborhood* execute(const char configuration_file[]);
};
