#pragma once

#include "../Combinations.h"
#include "../GreaterThanPolinomyals.h"
#include "../operators/OPF_Operator.h"
#include "../RandomNumber.h"


class DECISIONAID_LIB OPF_DTLZ9 : public OPF_Operator {

public:    
    OPF_DTLZ9();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



