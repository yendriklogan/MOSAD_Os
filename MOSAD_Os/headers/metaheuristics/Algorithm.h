#pragma once

#include "../problems/Problem.h"
#include "../solutions/SolutionSet.h"
#include "../tools/Parameters.h"
#include "../tools/Requirements.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Algorithm {
	private:

	protected:
        SolutionSet* initial_set;           //Input parameter, initial set of solutions, might be NULL
        

        Problem* problem_;                  //Input parameter, problem solution
        Parameters param_;                  //Input parameter, storage of algorithm parameters

        SolutionSet* lastB_ = NULL;                //Output parameter
        SolutionSet last_;                  //Output parameter
        SolutionSet lastGeneration_;        //Output parameter

	public:
        Algorithm();
        Algorithm(Problem* problem);
        //virtual ~Algorithm() = 0;
        virtual void execute();
        virtual void initialize();
        virtual void initialize(Requirements* req);

        void addParameter(const char parameter[], ParameterValue val);
        void* getParameter(const char name[]);
        

        SolutionSet* getLastB();
        SolutionSet getSolutionSet();
        SolutionSet getLastGenerationSolutionSet();

        //BORRAR: para debug
        int repetidos;
        //-----------JMVM Codigo en pruebas -------------------
        //virtual void execute(SolutionSet initialP);
        //virtual void setMFE(int n);
};
