#pragma once

#include "../tools/Constantes.h"
#include "../tools/Parameters.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Instance {
	private:
		char in[Constantes::MAX_SIZE];

	protected:
		Parameters par;

	public:
		Instance();
		Instance(char in[]);
		virtual ~Instance() = 0;

		virtual ParameterValue get(const char parameter[]);
		virtual void set(const char parameter[], ParameterValue value);
};
