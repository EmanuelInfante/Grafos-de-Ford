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
    // Agrega un arco al Nodo. Tienen que existir en el grafos, si no existen se retorna la función

    if(this ->obtenerNodo(nombreNodoI) == NULL || this ->obtenerNodo(nombreNodoF) == NULL)
        return;

    // Obtenemos los nodos
    Nodos *aux1 = this ->obtenerNodo(nombreNodoI), *aux2 = this ->obtenerNodo(nombreNodoF);

    // Creamos la arista
    Arista *aris = new Arista(costo, aux2);

    // Si es la primera arista/arco, se agrega directamente
    if(aux1 ->getAristaAdyacente() == NULL)
        aux1 ->setAristaAdyacente(aris);
    //Si ya hay arcos/aristas, se agrega a la posición final
    else
        aux1 ->aristaAdyacente ->agregarArista(costo, aux2);
}


Nodos* Nodos::obtenerNodo(char nombreNodo)
{
    // Retorna el nodo si existe, en caso contrario retorna el nodo. Este método es recursivo
    if(this ->nombreNodo == nombreNodo)
        return this;

    else if(this ->siguienteNodo == NULL)
        return NULL;

    return this ->siguienteNodo ->obtenerNodo(nombreNodo);
}


int Nodos::obtenerCostoNodos(char nodoI, char nodoF)
{
    // Obtiene el costo de la arista de un nodo a otro, si no existe retorna infinito

    // Si la arista no es esta, se revisa la siguiente
    if(this ->nombreNodo != nodoI && this ->siguienteNodo != NULL)
        return this ->siguienteNodo ->obtenerCostoNodos(nodoI, nodoF);
    // SI la arista es esta, se retorna
    else if(this ->nombreNodo == nodoI)
        return this ->aristaAdyacente ->obtenerCostoArista(nodoF);
    //En caso contrario, se retorna infinito
    else
        return std::numeric_limits<int>::max();

}
