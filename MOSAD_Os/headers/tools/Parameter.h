#pragma once

#include <iostream>
#include <cstdarg>
#include "ParameterValue.h"
#include "data/Interval.h"
#include "Constantes.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Parameter {
private:
	char name[Constantes::MAX_SIZE];
	ParameterValue value;
	int tipo_objeto = 0;
	int num_dim = 0;
	int* s_dim = NULL;


public:
	Parameter();
	Parameter(const char parameter[], ParameterValue val);
	Parameter(const char parameter[], ParameterValue val, int tipo_objeto, int num_dim, ...);
	~Parameter();

	void setName(const char parameter[]);
	void setValue(ParameterValue val);
	void setValue(ParameterValue val, int tipo_objeto, int num_dim, ...);

	char* getName();
	ParameterValue getValue();

	bool operator==(const Parameter& op);
	bool operator==(const char name[]);


	DECISIONAID_LIB friend ostream& operator<<(ostream& os, const Parameter& dt);

    };
