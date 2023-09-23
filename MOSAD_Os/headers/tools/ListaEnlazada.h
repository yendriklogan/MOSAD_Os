#pragma once

#include <iostream>
#include "Parameter.h"

#include "../../WindowsRequirements.h"

struct DECISIONAID_LIB nodo {
    Parameter nro;       
    struct nodo* sgte;
};


typedef struct nodo* Tlista;

class DECISIONAID_LIB ListaEnlazada {
    private:
        Tlista lista;
        int size;

    public:
        ListaEnlazada();

        Tlista getInicio();
        void insertarInicio(Parameter valor);
        void insertarFinal(Parameter valor);
        Parameter* buscarElemento(const char name[]);       
        bool eliminarElemento(const char name[]);
        int getSize();
        void vaciar();

        DECISIONAID_LIB friend ostream& operator<<(ostream& os, const ListaEnlazada& dt);

        //void eliminaRepetidos(Parameter valor);
        //int insertarAntesDespues();
        //void insertarElemento(Parameter valor, int pos);
};
