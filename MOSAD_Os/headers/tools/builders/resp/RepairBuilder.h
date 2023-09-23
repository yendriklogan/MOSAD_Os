#pragma once

#include "../Requirements.h"
#include "../Constantes.h"
#include "../operators/interval/PDTLZ_Repair.h"
#include "../operators/interval/DERepairV1.h"
#include "../operators/interval/DERepairV2.h"
#include "../operators/interval/DERepairV3.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../WindowsRequirements.h"

class DECISIONAID_LIB RepairBuilder : public GenericBuilder {
private:
	static RepairOperator* built(Requirements* req);

	RepairBuilder();

public:
	static RepairOperator* execute(Requirements* req);
	static RepairOperator* execute(const char configuration_file[]);
};
