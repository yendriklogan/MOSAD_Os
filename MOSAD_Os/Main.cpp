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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
