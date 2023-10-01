// MOSAD_Os.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "headers/MOSAD_O.h"
#include "headers/MOSAD_O_II.h"
#include "headers/Output.h"


int main()
{

    SolutionSet P;
    string path = "M_Config.txt";
    int algorithm = 0;
    
    
    if (algorithm == 0)
    {
        std::cout << "MOSA/D_O...\n";
        MOSAD_O* algo = new MOSAD_O();
        Requirements* config = new Requirements(path.c_str());
        algo->initialize(config);
        algo->execute();
        P = algo->getSolutionSet();
    }

    if (algorithm == 1)
    {
        std::cout << "MOSA/D_O_II...\n";
        MOSAD_O_II* algo = new MOSAD_O_II();
        Requirements* config = new Requirements(path.c_str());
        algo->initialize(config);
        algo->execute();
        P = algo->getSolutionSet();
    }

    Output::showOnlyObjectives(P);

}


