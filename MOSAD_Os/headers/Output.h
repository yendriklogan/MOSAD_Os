#pragma once
#include "../headers/Solutions/Solution.h"
#include "../headers/Solutions/SolutionSet.h"
#include "../../WindowsRequirements.h"


class Output {
 
private:
    static void showSolution(Solution s, int vista);
    static void saveSolution(Solution s, ofstream *file);
   
public:
    
    Output();
    static void showVarsAndObjs(SolutionSet P);
    static void showOnlyVariables(SolutionSet P);
    static void showOnlyObjectives(SolutionSet P);
    static void saveSolutionSet(SolutionSet P, string fileName);
};



