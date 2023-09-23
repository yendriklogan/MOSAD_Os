#pragma once


#include "../../tools/Constantes.h"
#include "../../preferences/outranking/NetFlowInteraction.h"
#include "../../preferences/outranking/InteractModel.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB InteractBuilder : public GenericBuilder {
private:
	static InteractModel* built(Requirements* req);

	InteractBuilder();

public:
	static InteractModel* execute(Requirements* req);
	static InteractModel* execute(const char configuration_file[]);
};
