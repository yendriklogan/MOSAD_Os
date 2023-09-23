#pragma once

#include "../Combinations.h"
#include "../GreaterThanPolinomyals.h"
#include "../operators/OPF_Operator.h"
#include "../RandomNumber.h"


class DECISIONAID_LIB OPF_DTLZ7 : public OPF_Operator {
    int BASE = 5000;
    double PROPORCION = 10000.0;

    int k;    

    GreaterThanPolinomyals* gtp;

public:    
    OPF_DTLZ7();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



