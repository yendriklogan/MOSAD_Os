#pragma once

#include "COENeighborhoodOperator.h"

#include "../../../../WindowsRequirements.h"

class DECISIONAID_LIB COEPermutationNeighborhood : public COENeighborhoodOperator {
    private:

    public:
        Solution* execute(Solution* actual) override;
        void initialize(Requirements* config) override;
};
