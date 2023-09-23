#pragma once

#include "../operators/OPF_Operator.h"
#include "../RandomNumber.h"


class DECISIONAID_LIB OPF_DTLZ3 : public OPF_Operator {
    int k;

public:    
    OPF_DTLZ3();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



