#pragma once

#include <cstdarg>

#include "../tools/Constantes.h"
#include "../tools/Parameters.h"
#include "../tools/EasyFileHandler.h"
#include "../tools/ListaEnlazada.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Requirements {
	//CAMBIAR A Configuration
	//permitir que sea de diferentes tipos la carga (p.e. desde JSON)
	//

private:
	Parameters* requirements_missing = NULL;
	Parameters* requirements_info = NULL;
	Parameters* requirements_list = NULL;
	EasyFileHandler* configuration_file = NULL;

	void add(const char requirement[], int tipo_req, int num_dim, ...);	//add a new [requirement] and associates it with some information (tipo del requerimiento, numero de dimensiones (0 - SINGLE, 1 - VECTOR, 2 - MATRIZ), tipo_dato, [dim1], [dim2])
public:
	Requirements(const char file[]);					//configuration file having the values for the requirements

	void addMatrix(const char requirement[], int type, int num_rows, int num_cols);
	void addVector(const char requirement[], int type, int num_elements);
	void addValue(const char requirement[], int type);
	
	Parameters* load();									//load in memory the requirement information
};
