#ifndef GRAFOS_H
#define GRAFOS_H

#include <iostream>
#include "Nodos.h"

using namespace std;

// Prototipo de Distancias
struct Distancias;


class Grafos
{
    public:
        Grafos();
        virtual ~Grafos();

        void algoritmoBellmanFord(char nombreNodo);

    protected:

    private:
        Distancias **inicializarValoresAlgoritmoFord(char nombreNodo);
        string cantidadEspacios(int numero);
        bool continuarAlgoritmo(Distancias **distanciasAnterior, Distancias **distanciasActual);
        int cantidadNodos;
        Nodos *nodos;

        //Métodos privados
        void crearNodosDefecto();
};

#endif // GRAFOS_H
