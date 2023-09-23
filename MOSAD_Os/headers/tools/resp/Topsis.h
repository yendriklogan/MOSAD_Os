#pragma once

#include "../tools/data/Interval.h"
#include "../problems/Problem.h"
#include "../solutions/SolutionSet.h"

#include "../tools/Constantes.h"
#include "../tools/Dominance.h"
#include "../tools/sorting/MergeSort.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Topsis {
private:
	SolutionSet m_decision;				//Input: vector a ordenar o matriz de decision
	Interval* weights;					//Input: pesos de los objetivos

	//variables locales a [execute]
	SolutionSet* front;					//Output: ranking de las soluciones
	Interval** m_decision_norm = NULL;	//Internal Process: matriz de decision normalizada
	Interval** m_decision_pond = NULL;	//Interal Process: matriz de decision ponderada
	Interval* vector_norma = NULL;		//Internal process: vector normalizado

	int* order = NULL;					//Internal Process: indice ordenado de la matriz de decision

	Interval* ideal;					//Internal Process: vector de alternativa ideal
	Interval* anti_ideal;				//Internal Process: vector de alternativa antiideal

	Interval* dis_ideal;
	Interval* dis_anti;

					//Internal Process: Proximidad relativa a la alternativa ideal

	int N = 0;							//Internal Process: Numero de soluciones
	int M = 0;							//Internal Porcess: Numero de objetivos
	double* RS = NULL;

public:
	
	Topsis();
	Topsis(SolutionSet s);
	void initialize(SolutionSet s, Interval* w);
	SolutionSet* execute();
	void changeSet(SolutionSet s);

	//metodos caracteristicos de TOPSIS
	double* getRS();
};

/*
	NOTA DE IMPLEMENTACION:
		> El uso de intervalos no ESTA COMPLEMENTAMENTE soportado debido al cálculo de la division, cuando los intervalos consideran 0s, se generan infinitos
*/