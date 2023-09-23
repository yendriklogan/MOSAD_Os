#pragma once

#include "../operators/OPF_Operator.h"


class DECISIONAID_LIB OPF_DTLZ1 : public OPF_Operator {


    int k;

public:    
    OPF_DTLZ1();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



