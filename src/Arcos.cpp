#include "Arcos.h"

Arcos::Arcos(char nodoInicial, char nodoFinal, int valorArco)
{
    this ->nodoInicial = nodoInicial;
    this ->nodoFinal = nodoFinal;
    this ->valorArco = valorArco;
}

Arcos::~Arcos()
{
    //dtor
}
