#ifndef ARISTA_H
#define ARISTA_H

#include "Nodos.h"

class Nodos;

class Arista
{
    public:
        Arista(int costo, Nodos *nodoLlegada);
        virtual ~Arista();

        void setCosto(int costo) { this ->costo = costo; };
        void agregarArista(int costo, Nodos* nodo);
        int getCosto() { return this ->costo; };
        int obtenerCostoArista(char nodoLlegada);

    protected:

    private:
        int costo;
        Nodos *nodoLlegada;
        //Puntero que apunta a la siguiente arista del nodo
        Arista *siguienteArista;

};

#endif // ARISTA_H
