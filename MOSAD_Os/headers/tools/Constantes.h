#pragma once

#include <climits>

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB Constantes {                  //CHECK: https://en.cppreference.com/w/cpp/types/numeric_limits
    public:        
        static const double MINDOUBLE;              //NUMERIC LIMITS: https://en.cppreference.com/w/cpp/types/numeric_limits/max
        static const double MAXDOUBLE;              //CORREGIR ERROR C2861 (Inicialización de miembros estaticos): CHECK: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-2/compiler-error-c2864?view=vs-2019

        static const int MIN_INT;
        static const int MAX_INT;

        static int VERBOSE;

        //static const int MAX_SIZE = 255;
        static const int MAX_SIZE = 1024;
        static const int LINE_SIZE = 1024;
        static const int OBJETO = 0;
        static const int INT = 1;
        static const int LONG = 3;
        static const int FLOAT = 7;
        static const int LONGLONG = 15;
        static const int DOUBLE = 31;
        static const int CHAR = 63;
        static const int STRING = 127;
        static const int INTERVAL = 255;
        static const int LINE = 511;
        static const int VECTOR = 1023;
        static const int MATRIX = 2047;

        static void* generateVector(int S, int tipo);
        static void* generateMatrix(int F, int C, int tipo);

        //For problems/Problem.h
        static const int MINIMIZATION = -1;
        static const int MAXIMIZATION = 1;        
};