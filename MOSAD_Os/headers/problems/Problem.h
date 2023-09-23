#pragma once

#include "../tools/data/Interval.h"
#include "../tools/Requirements.h"
#include "../../WindowsRequirements.h"

class Instance;
class Solution;
class SolutionSet;

class DECISIONAID_LIB Problem {
    protected:
        int numberOfObjectives_;
        int numberOfVariables_;
        int numberOfConstraints_;

        int* objs_type;
        Interval* lowerBounds_;
        Interval* upperBounds_;

    public:
        virtual ~Problem();
        virtual void initialize(Requirements* config);

        int* getObjectivesType();
        Interval* getUpperBounds();
        Interval* getLowerBounds();

        void setUpperBound(int variable, Interval value);
        void setLowerBound(int variable, Interval value);
        Interval getUpperBound(int variable);
        Interval getLowerBound(int variable);

        int getNumberOfConstraints();
        int getNumberOfVariables();
        int getNumberOfObjectives();

        virtual void evaluateConstraints(Solution* s);

        virtual void evaluate(Solution* s);
        
        virtual Solution generateRandomSolution();
        virtual SolutionSet generateFromSolutionSet(Interval** solutions, int num_sol);
        Solution generateOptimalSolution();
        Solution generateExistingSolution();        
        Solution generateFixedSolution();

        virtual Instance* getInstance();

        Problem operator=(const Problem& op);
};
