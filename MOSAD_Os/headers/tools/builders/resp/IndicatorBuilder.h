#pragma once

#include "../Constantes.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"
#include "../../../include/tools/indicators/Indicator.h"
#include "../../../include/tools/indicators/IGD.h"

class DECISIONAID_LIB IndicatorBuilder : public GenericBuilder {
private:
	static Indicator* built(Requirements* req);
	IndicatorBuilder();

public:
	static Indicator* execute(Requirements* req);
	static Indicator* execute(const char configuration_file[]);
};
