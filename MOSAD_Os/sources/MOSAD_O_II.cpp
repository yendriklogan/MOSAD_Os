//
#include "../headers/MOSAD_O_II.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;


MOSAD_O_II::MOSAD_O_II() : Algorithm(NULL) {

}

void MOSAD_O_II::initialize() {

}

void MOSAD_O_II::initialize(Requirements* config) {
    config->addValue("#maxEvaluations", Constantes::INT);
    config->addValue("#Ti", Constantes::DOUBLE);
    config->addValue("#Tf", Constantes::DOUBLE);
    config->addValue("#N", Constantes::INT);
    config->addValue("#L", Constantes::INT);
    config->addValue("#alpha",Constantes::DOUBLE);
    config->addValue("#Problem-Instance", Constantes::STRING);
    config->addValue("#NUM-INITIAL-SOLS", Constantes::INT);


    this->param_ = *(config->load());

    this->problem_ = ProblemBuilder::execute(this->param_.get("#Problem-Instance").getString());

    this->Ti = this->param_.get("#Ti").getDouble();
    this->Tf = this->param_.get("#Tf").getDouble();

    this->N = this->param_.get("#N").getInt();
    this->L = this->param_.get("#L").getInt();
    this->alpha = this->param_.get("#alpha").getDouble();

    this->maxEvaluations = this->param_.get("#maxEvaluations").getInt();
    //Configure more specific algorithm data structures
    P= new SolutionSet(this->N, this->problem_);
    currentP = new SolutionSet(this->N, this->N, this->problem_);
    //EP = new SolutionSet(this->maxEvaluations, this->problem_);
    //PGenerations = new SolutionSet(this->maxEvaluations, this->problem_);

    randomSolutions =new SolutionSet(3, this->problem_);
    parents = new SolutionSet(2, this->problem_);
    children = new SolutionSet(2, 2, this->problem_);
    candidate = new Solution(this->problem_);
    trial = new Solution(this->problem_);
    abs = (Interval*)Constantes::generateVector(trial->getNumObjectives(), Constantes::INTERVAL);
   

    /*this->repair = RepairBuilder::execute(config);*/
    this->DEMutation = DEMutationBuilder::execute(config);
    this->crossover = CrossoverBuilder::execute(config);

    this->om = (FDEA_Outranking*)OutrankingModelBuilder::execute(config);
    //this->om = (PDTLZ_Outranking*)OutrankingModelBuilder::execute(config);
    this->om->setProblem(this->problem_);

    vectorWeights = WeightVectorBuilder::execute(config);
    this->unitVectors = vectorWeights->execute();

    //Inicializar MINIMO Y MAXIMO
    Z_min = (Interval*)Constantes::generateVector(this->problem_->getNumberOfObjectives(), Constantes::INTERVAL);
    Z_max = (Interval*)Constantes::generateVector(this->problem_->getNumberOfObjectives(), Constantes::INTERVAL);

    for (int i = 0; i < this->problem_->getNumberOfObjectives(); ++i) {
        Z_min[i] = Constantes::MAXDOUBLE;
        Z_max[i] = Constantes::MINDOUBLE;
    }
    random = RandomNumber::getInstance();
    //Definir INITIAL SET of solutions and load them
    Instance* i = this->problem_->getInstance();
    int num_is = this->param_.get("#NUM-INITIAL-SOLS").getInt();

    if (num_is > 0) {
        char sol_name[] = "#INITIAL-SOLUTIONS";

        config->addMatrix("#INITIAL-SOLUTIONS", Constantes::DOUBLE, num_is, this->problem_->getNumberOfVariables());

        this->param_ = *(config->load()); //hay que implementar una estrategai para que una llamada adicional a load no borre lo anterior

        double** dsols = (double**)this->param_.get("#INITIAL-SOLUTIONS").getValue();
        Interval** sols = (Interval**)Constantes::generateMatrix(num_is, this->problem_->getNumberOfVariables(), Constantes::INTERVAL);

        for (int i = 0; i < num_is; ++i) {
            for (int j = 0; j < this->problem_->getNumberOfVariables(); ++j) {
                sols[i][j] = dsols[i][j];
            }
        }

        this->initial_set = new SolutionSet(num_is, this->problem_);
        *this->initial_set = this->problem_->generateFromSolutionSet(sols, num_is);
    }

    //Inicializar Estructuras Espec�ficas del Algoritmo
    this->lastGeneration_.initialize(this->N, problem_);

}

void MOSAD_O_II::execute()
{
    //Generar la poblacion inicial P de tama�o N
    Solution newSolution(problem_);

    int MFE = maxEvaluations;
    int FE = 0;

    for (int n = 0; n < this->N; n++) {
        newSolution = problem_->generateRandomSolution();
        problem_->evaluate(&newSolution);
        problem_->evaluateConstraints(&newSolution);
        //EP->add(newSolution);
        P->add(newSolution);
        obtainIdealPoint(newSolution);
        FE++;
    }
    
    
    /*ofstream out("MOSAD_initial_solutions.txt");
    out << *P;
    out.close();*/

    Solution current(this->problem_);

    int cont = 0;
    bool elegido = false;
    int idx = 0;

    while (Ti >= Tf && FE <= MFE) {

        //cout << "Evaluaciones" << FE<<"\n";
        for (int k = 0; k < N; k++)//copiar la poblacion actual
        {
            currentP->set(k, P->get(k));
        }

        for (int i = 0; i < N; i++)//por cada subproblema
        {
            //-----------------------------------------------------------           
            current = currentP->get(i);
            //-------------------------------------------

            //actual = P->get(i);

            for (int j = 0; j < L; j++)
            {
                FE++;
                newSolution = perturbation(current);
                //mutation->execute(nueva);
                problem_->evaluate(&newSolution);
                //problem_->evaluateConstraints(&nueva);
                //this->EP->add(nueva);

                double p = random->nextDouble();
                double b = probabilityFunction(newSolution, current, Ti);

                Interval v1 = g(newSolution, unitVectors[i], Z_min);
                Interval v2 = g(P->get(i), unitVectors[i], Z_min);

                om->outranking(newSolution.getObjectives(), P->get(i).getObjectives());
                bool xPy = om->getStrictPreference_XY();


                if (v1 <= v2)
                {
                    current = newSolution;

                    if (xPy == true)
                        P->set(i, newSolution);
                    else
                        if (p < b)
                        {
                            P->set(i, newSolution);
                        }
                }

                obtainIdealPoint(newSolution);
            }
        }
        Ti = alpha * Ti;
    }

    //mostrarArchivo1();

    this->last_ = *P;
}

Solution MOSAD_O_II::perturbation(Solution original)
{
    parents->clear();
    randomSolutions->clear();
    Solution diver;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    n1 = random->nextInt(N - 1);
    n2 = random->nextInt(N - 1);
    n3 = random->nextInt(N - 1);
    //n3 = aleatorio->nextInt(EP->size() - 1);

    randomSolutions->add(currentP->get(n1));
    randomSolutions->add(currentP->get(n2));
    randomSolutions->add(currentP->get(n3));

    DEMutation->execute(*randomSolutions, *trial);

    parents->add(*trial);
    parents->add(original);

    crossover->execute(*parents, *children);
    *candidate = children->get(0);

    return *candidate;
}

Interval MOSAD_O_II::g(Solution original, Interval* vector, Interval* z_min)
{
    Interval c = 0;
    objs = original.getObjectives();

    for (int i = 0; i < original.getNumObjectives(); i++)
    {
        Interval x = z_min[i];
        abs[i] = iabs(objs[i] - z_min[i]);
    }

    for (int i = 0; i < original.getNumObjectives(); i++)
    {
        abs[i] = abs[i] * vector[i];
    }

    Interval max = 0;
    for (int i = 0; i < original.getNumObjectives(); i++)
    {
        if (abs[i] > max)
        {
            max = abs[i];
        }
    }

    return max;
}

void MOSAD_O_II::obtainIdealPoint(Solution p)
{
    for (int i = 0; i < this->problem_->getNumberOfObjectives(); ++i) {
            if (Z_max[i] < p.getObjective(i)) {
                Z_max[i] = p.getObjective(i);
            }

            if (Z_min[i] > p.getObjective(i)) {
                Z_min[i] = p.getObjective(i);
            }
    }

}

double MOSAD_O_II::probabilityFunction(Solution nueva, Solution actual, double T)
{
    Interval p_engrand = 0;
    Interval p_classic = 0;
    Interval suma_engrand = 0;
    Interval suma_classic = 1;

    Interval* xActual = actual.getObjectives();
    Interval* xNueva = nueva.getObjectives();
    int nObj = nueva.getNumObjectives();
    for (int i = 0; i < nObj; i++)
    {
        if (xNueva[i].L > xActual[i].L) {
            if (xActual[i] == 0) {
                suma_classic = suma_classic + xNueva[i] - xActual[i];
            }
            else {
                suma_engrand = suma_engrand + log(xNueva[i] / xActual[i]);
            }
        }
    }

    p_engrand = exp(suma_engrand * (-1 / T));
    p_classic = exp(suma_classic * (-1 / T));

    return p_engrand < p_classic ? p_engrand.L : p_classic.L;
}
