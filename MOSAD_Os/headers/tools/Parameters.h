#pragma once

#include <iostream>
#include "ListaEnlazada.h"
#include "Parameter.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Parameters {
	private:
		ListaEnlazada inputParameters;
			
	public:
		void setInputParameter(const char parameter[], ParameterValue val);
		void setInputParameter(const char parameter[], ParameterValue val, int tipo_objeto, int dim1);
		void setInputParameter(const char parameter[], ParameterValue val, int tipo_objeto, int dim1, int dim2);

		void* getInputParameter(const char parameter[]);

		ParameterValue get(const char parameter[]);
		Tlista getFirstParameter();

		int getSize();
		DECISIONAID_LIB friend ostream& operator<<(ostream& os, const Parameters& dt);
};