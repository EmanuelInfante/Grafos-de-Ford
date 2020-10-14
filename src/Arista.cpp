#include "Arista.h"
#include <limits>
#include <iostream>
#include <cstddef>

Arista::Arista(int costo, Nodos *nodoLlegada)
{
    this ->costo = costo;
    this ->nodoLlegada = nodoLlegada;
    this ->siguienteArista = NULL;
}

Arista::~Arista()
{
    //dtor
}


void Arista::agregarArista(int costo, Nodos* nodo)
{
    // Agrega una arista con su destino
    if(this ->siguienteArista == NULL)
    {
        this ->siguienteArista = new Arista(costo, nodo);

    }
    else
        this ->siguienteArista ->agregarArista(costo, nodo);
}


int Arista::obtenerCostoArista(char nodoLlegada)
{
    // Método que retorna el costo de la arista solicitada, si no existe retorna infinito

    if(this ->nodoLlegada ->getNombreNodo() == nodoLlegada)
    {

        return this ->costo;
    }

    else if(this ->siguienteArista == NULL)
        return std::numeric_limits<int>::max();
    return this ->siguienteArista ->obtenerCostoArista(nodoLlegada);

}
