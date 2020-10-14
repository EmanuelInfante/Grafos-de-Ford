#ifndef GRAFOS_H
#define GRAFOS_H

#include "Nodos.h"

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
        bool continuarAlgoritmo(Distancias **distanciasAnterior, Distancias **distanciasActual);
        int cantidadNodos;
        Nodos *nodos;

        //Métodos privados
        void crearNodosDefecto();
};

#endif // GRAFOS_H
