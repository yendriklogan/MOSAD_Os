#pragma once

#include "../../tools/ListaEnlazada.h"
#include "../../tools/Constantes.h"
#include "../../../WindowsRequirements.h"
#include "../../tools/builders/OutrankingModelBuilder.h"
#include "../../preferences/outranking/FDEA_Outranking.h"
#include "../builders/OPF_Builder.h"
#include "../builders/ProblemBuilder.h"


class DECISIONAID_LIB BC_DTLZ {
    Parameters param_;
    Problem* problem_;    
    FDEA_Outranking* om;                      //Input parameter [outranking model for DM]
    OPF_Operator* opf;

    int SIZE = 20000;

    ListaEnlazada bc;                                  //Ouput best compromise identified

public:
    
    BC_DTLZ();

    void initialize(const char file[]);
    void initialize(Requirements* req);
    void execute();

    ListaEnlazada getBestCompromise();
};



