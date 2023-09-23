#pragma once

#include "../operators/OPF_Operator.h"
#include "../RandomNumber.h"


class DECISIONAID_LIB OPF_DTLZ4 : public OPF_Operator {
    int k;

public:    
    OPF_DTLZ4();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



