#pragma once

#include "../Combinations.h"
#include "../GreaterThanPolinomyals.h"
#include "../operators/OPF_Operator.h"
#include "../RandomNumber.h"


class DECISIONAID_LIB OPF_DTLZ8 : public OPF_Operator {
    int using_hyperplane = false; //alternate the use of solutions in front found at the related line (yes) or related hyperplane (yes)
                                  // if [false] solution created at [execute] will be at the line of the front
                                  // if [true] solution created at [execute] will be at the hyperplane of the front
public:    
    OPF_DTLZ8();

    void initialize(Requirements* req) override;
    void execute(Solution* sol) override;
};



