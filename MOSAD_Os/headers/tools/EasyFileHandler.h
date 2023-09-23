#pragma once

#include <iostream>
#include <fstream>
#include "Parameters.h"
#include "StringHandler.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB EasyFileHandler {
    private:
        char path_file[Constantes::MAX_SIZE];

    public:
        EasyFileHandler(const char file[]);
        ParameterValue* readValue(const char tag[], int tipo);
        ParameterValue* readVector(const char tag[], int tipo, int num_elements);
        ParameterValue* readMatrix(const char tag[], int tipo, int num_fil, int num_col);
};
