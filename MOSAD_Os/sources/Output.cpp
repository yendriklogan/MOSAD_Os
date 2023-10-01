//
#include "../headers/Output.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;


Output::Output() {

}

void Output::showVarsAndObjs(SolutionSet P)
{
    for (int i = 0; i < P.size(); i++)
    {
        std::cout << i + 1 << ") ";
        Output::showSolution(P.get(i), 1);
        std::cout << "\n";
    }
}

void Output::showOnlyVariables(SolutionSet P)
{
    for (int i = 0; i < P.size(); i++)
    {
        std::cout << i + 1 << ") ";
        showSolution(P.get(i), 2);
        std::cout << "\n";
    }
}

void Output::showOnlyObjectives(SolutionSet P)
{
    for (int i = 0; i < P.size(); i++)
    {
        std::cout << i + 1 << ") ";
        showSolution(P.get(i), 3);
        std::cout << "\n";
    }
}

void Output::showSolution(Solution s, int vista)
{
    int var = 0;
    int objs = 0;
    var = s.getNumVariables();
    objs = s.getNumObjectives();
    if (vista == 2 || vista ==1)
    {
        std::cout << "[ ";
        for (int i = 0; i < var; i++)
        {
            std::cout << s.getVariableValue(i);
            std::cout << " ";
        }
        std::cout << "] ";
    }
    if (vista == 3|| vista == 1)
    {
        std::cout << "[ ";
        for (int i = 0; i < objs; i++)
        {
            std::cout << s.getObjective(i);
            std::cout << " ";
        }
        std::cout << "]";
    }
    
}

void Output::saveSolutionSet(SolutionSet P, string fileName)
{
    ofstream* file=new ofstream(fileName);
    for (int i = 0; i < P.size(); i++)
    {
        Output::saveSolution(P.get(i), file);
        *file << "\n";
    }
    file->close();
}

void Output::saveSolution(Solution s, ofstream* file)
{
    int var = s.getNumVariables();
    int objs = s.getNumObjectives();
    *file << "[ ";
    for (int i = 0; i < var; i++)
    {
        *file << s.getVariableValue(i);
        *file << " ";
    }
    *file << "] ";
    *file << "[ ";
    for (int i = 0; i < objs; i++)
    {
        *file << s.getObjective(i);
        *file << " ";
    }
    *file << "]";
}
