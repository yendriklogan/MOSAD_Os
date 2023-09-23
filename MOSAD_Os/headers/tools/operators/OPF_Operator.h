#pragma once
/*
* Implementacion de algoritmo FDEA-I de (Qiu et al., 2021) - Evolutionary many-Objective algorithm based on fractional dominance relation and improved objective space decomposition strategy.
*/


//#include "Algorithm.h"
#include "../../tools/Constantes.h"
#include "../../../WindowsRequirements.h"
#include "../../tools/builders/OutrankingModelBuilder.h"
#include "../../preferences/outranking/FDEA_Outranking.h"
#include "Operator.h"

class DECISIONAID_LIB OPF_Operator : public Operator {

protected:
    char problem_name[Constantes::MAX_SIZE] = "";

public:    
    virtual void initialize(Requirements* req);
    OPF_Operator();
    virtual void execute(Solution* sol);
    char* getName();
};



