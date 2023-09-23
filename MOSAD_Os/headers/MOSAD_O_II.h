#pragma once
/*
* Implementacion de algoritmo MOSA de (Phillippe Engrand, 1998) - A multi-objective optimization approach based on simulated annealing and its application to nuclear fuel management.
*/
#include "../headers/metaheuristics/Algorithm.h"
#include "../headers/instances/Instance.h"
#include "../headers/tools/data/Interval.h"

#include "../headers/tools/builders/ProblemBuilder.h"
#include "../headers/tools/builders/CrossoverBuilder.h"
#include "../headers/tools/operators/interval/CrossoverOperator.h"
//#include "../headers/tools/builders/MutationBuilder.h"
//#include "../headers/tools/operators/interval/MutationOperator.h"
#include "../headers/tools/builders/DEMutationBuilder.h"
#include "../headers/tools/operators/interval/DEMutationOperator.h"
#include "../headers/tools/builders/WeightVectorBuilder.h"
#include "../headers/tools/operators/interval/WeightVectorModel.h"
//#include "../headers/tools/builders/SelectionBuilder.h"
//#include "../headers/tools/operators/interval/MoeadSelection.h"
#include "../headers/tools/builders/CrossoverBuilder.h"
#include "../headers/tools/operators/interval/CrossoverOperator.h"
//#include "../headers/tools/builders/RepairBuilder.h"
//#include "../headers/tools/operators/interval/RepairOperator.h"
//#include "../headers/tools/builders/ImprovementBuilder.h"
//#include "../headers/tools/operators/interval/ImprovementOperator.h"
#include "../headers/tools/Constantes.h"
#include "../../WindowsRequirements.h"


class MOSAD_O_II : public Algorithm {
    int maxEvaluations = -1;             //Input parameter, stop criterion, number of maximum evaluations of the objective functions (ONE evaluation corresponds to the computation of all the [m] objectives assocaited to the problem solved
    int N = -1;                          //Size of population
    int FE = 0;
    double Ti = 0;
    double Tf = 0;
    double alpha;
    int L=0;
    
    //MutationOperator* mutation = NULL;      //Input parameter [it is a Model]
    //RepairOperator* repair = NULL;          //Input parameter [it is a Model]
    DEMutationOperator* DEMutation = NULL;  //Input parameter [it is a Model]
    CrossoverOperator* crossover = NULL;    //Input parameter [it is a Model]
    //FastNonDominatedSort sorting;               //for sorting
    RandomNumber* random;

    FDEA_Outranking* om;
    //PDTLZ_Outranking* om;

    //NOTA el rango [a, b] de cada variable de decision se define en el problema
    SolutionSet* P;
    SolutionSet* currentP;
    SolutionSet* PGenerations;
    Interval* Z_min = NULL;
    Interval* Z_max = NULL;
    //variable de visualizacion de datos
    int ver = 0;

    //Unit Direction Operators
    WeightVectorModel* vectorWeights = NULL;   //Input parameter [it is a Model]
    Interval** unitVectors = NULL;             //built from model

    SolutionSet *randomSolutions;
    SolutionSet *parents;
    SolutionSet *children;
    Solution* candidate;
    Solution* trial;
    Interval* objs;
    Interval* abs;


private:
     
    double probabilityFunction(Solution nueva, Solution actual, double T);
    Solution perturbation(Solution original);
    void obtainIdealPoint(Solution p);
    Interval g(Solution original, Interval* vector, Interval* z_min);

    //variables locales [estaticas por eficiencia]
public:
    MOSAD_O_II();
    void initialize() override;
    void initialize(Requirements* config) override;
    void execute() override;
};



