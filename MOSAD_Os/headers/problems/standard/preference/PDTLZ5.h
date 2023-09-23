#pragma once

#include "PDTLZ.h"
#include "../../../../WindowsRequirements.h"

#define M_PIl  3.141592653589793238462643383279502884L

class DECISIONAID_LIB PDTLZ5 : public PDTLZ {
public:
	PDTLZ5();
	PDTLZ5(Instance_PDTLZ1* inst, int dm);

	double g(Solution* s) override;

	void evaluate(Solution* s) override;
};




