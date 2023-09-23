#pragma once

#include "../tools/Requirements.h"

#include "../../WindowsRequirements.h"

/*
* El proposito futuro de esta clase es que sea un Builder Generico que se actualice en tiempo de desarrollo al usar el Framework 
*/

class DECISIONAID_LIB GenericBuilder {
	protected:
		GenericBuilder();

		//Requirements* config;
		static Parameters* clases;
		static Parameters* getClases();

	public:
		
		static void add(const char name[], void* clase);
		//GenericBuilder(const char configuration_file[]);
		//void add(const char name[], void* (*init)(Requirements* req) );
		//void* built(const char name[]);

};
