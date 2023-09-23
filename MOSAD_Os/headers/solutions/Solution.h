#pragma once

#include "../tools/data/Interval.h"

#include "../../WindowsRequirements.h"

class Problem;

class DECISIONAID_LIB Solution {
	protected:
        int ID = 0;                             //ID of solution
        char* name;
        Problem* problem_;
        int rank;
        Interval *ind;                          //decision variables
        Interval *objs;                         //Los objetivos deberán ser de minimización
        Interval *res;                          //The value of the resources given the decision variable values in IND
        Interval overallConstraintViolation;    //el valor deberá ser negativo, para representar cantidad total violada
        int numberOfViolatedConstraints;
        int *restricciones_violadas;

    public:
        Solution();
        Solution(Problem* problem);

        void initialize(Problem* problem);

        Interval* getDecisionVariables();
        int getNumVariables();
        Interval* getObjectives();
        int getNumObjectives();
        void setObjective(int obj, Interval value);
        Interval getObjective(int obj);
        void setVariableValue(int var, Interval value);
        Interval getVariableValue(int var);
        void setResourceValue(int var, Interval value);
        Interval getResourceValue(int var);
        void setOverallConstraintViolation(Interval total);
        Interval getOverallConstraintViolation();
        void setNumberOfViolatedConstraints(int number);
        int getNumberOfViolatedConstraints();
        int* getViolatedConstraints();
        void setConstraintViolation(int constraint, bool is_violated);
        void setRank(int rank);
        int getRank();
        Problem* getProblem();
        void setLowerBound(int var, Interval value);
        Interval getLowerBound(int var);
        void setUpperBound(int var, Interval value);
        Interval getUpperBound(int var);
        int getID();
        void setID(int ID);

        bool operator==(const Solution& op);
        Solution operator=(const Solution& op);

        DECISIONAID_LIB friend ostream& operator<<(ostream& os, const Solution& dt);
};
