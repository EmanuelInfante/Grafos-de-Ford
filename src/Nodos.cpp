#include <cstddef>
#include <limits>
#include "Nodos.h"
#include <iostream>

using namespace std;

Nodos::Nodos(char nombreNodo)
{
    //constructor para PRIMER NODO
    this ->nombreNodo = nombreNodo;
    this ->aristaAdyacente = NULL;
    this ->siguienteNodo = NULL;
}


Nodos::~Nodos()
{
    //dtor
}


void Nodos::agregarNodo(char nombreNodo)
{
    // Agrega un nodo nuevo al nodo inicial. estándo "conectados" todos los NOdos de la pila a ese gráfos
    if(this ->siguienteNodo == NULL)
        this ->siguienteNodo = new Nodos(nombreNodo);
    else
        this ->siguienteNodo ->agregarNodo(nombreNodo);
}


void Nodos::agregarArco(char nombreNodoI, char nombreNodoF, int costo)
{
    // Agrega un arco al Nodo

    if(this ->obtenerNodo(nombreNodoI) == NULL || this ->obtenerNodo(nombreNodoF) == NULL)
        return;

    Nodos *aux1 = this ->obtenerNodo(nombreNodoI), *aux2 = this ->obtenerNodo(nombreNodoF);

    Arista *aris = new Arista(costo, aux2);

    if(aux1 ->getAristaAdyacente() == NULL)
        aux1 ->setAristaAdyacente(aris);
    else
        aux1 ->aristaAdyacente ->agregarArista(costo, aux2);
}


Nodos* Nodos::obtenerNodo(char nombreNodo)
{
    // Retorna el nodo si existe, en caso contrario retorna el nodo
    if(this ->nombreNodo == nombreNodo)
    {
        return this;
    }

    else if(this ->siguienteNodo == NULL)
    {
        return NULL;
    }
    return this ->siguienteNodo ->obtenerNodo(nombreNodo);
}


int Nodos::obtenerCostoNodos(char nodoI, char nodoF)
{
    // Obtiene el costo de la arista de un nodo a otro, si no existe retorna infinito
    if(this ->nombreNodo != nodoI && this ->siguienteNodo != NULL)
        return this ->siguienteNodo ->obtenerCostoNodos(nodoI, nodoF);
    else if(this ->nombreNodo == nodoI)
    {

        return this ->aristaAdyacente ->obtenerCostoArista(nodoF);
    }

    else
        return std::numeric_limits<int>::max();

}




/*
int Nodos::obtenerCostoNodo(char nodo)
{
    //Recibe un nodo, y si existe retorna el costo hasta el nodo, en caso contrario retorna infinito
    if( this ->nodo == NULL)
        return std::numeric_limits<int>::max();
    if(nodo == this ->nombreNodo)
        return this ->costo;
    this ->obtenerCostoNodo(nodo);
}*/
