#pragma once

#include "../Parameters.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Operator {
	protected:
		ParameterValue VACIO = 0;
		Parameters param;

	public:
		void addParameter(const char mode[], const char parameter[], ParameterValue val);
		ParameterValue getParameter(const char mode[], const char parameter[]);

};
