#pragma once

#include "../Constantes.h"
#include "../sampling/OPF_DTLZ1.h"
#include "../sampling/OPF_DTLZ2.h"
#include "../sampling/OPF_DTLZ3.h"
#include "../sampling/OPF_DTLZ4.h"
#include "../sampling/OPF_DTLZ5.h"
#include "../sampling/OPF_DTLZ6.h"
#include "../sampling/OPF_DTLZ7.h"
#include "../sampling/OPF_DTLZ8.h"
#include "../sampling/OPF_DTLZ9.h"
#include "../operators/interval/ImprovementHassanien.h"
#include "../GenericBuilder.h"

#include "../Requirements.h"
#include "../../../WindowsRequirements.h"

class DECISIONAID_LIB OPF_Builder : public GenericBuilder {
private:
	static OPF_Operator* built(Requirements* req);

	OPF_Builder();

public:
	static OPF_Operator* execute(Requirements* req);
	static OPF_Operator* execute(const char configuration_file[]);
};
