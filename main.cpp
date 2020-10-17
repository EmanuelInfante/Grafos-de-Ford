#include <iostream>
#include "Grafos.h"

using namespace std;

int main()
{
    cout << "ALgoritmo Bellman Ford. Universidad Nacional ABierta" << endl;

    // Creamos el gráfo solicitado
    Grafos *graf = new Grafos();

    // Buscamos el nodo 'S'

    cout << "Ingrese el nodo por el cual va a iniciar el algoritmo, en caso de no ingresar un valor valido se iniciara por el valor S (A-B-C-D-E-F-G-S): ";

    char nodoInicial;

    cin >> nodoInicial;

    // Imprimimos el nodo inicial e iniciamos el algoritmo
    if(nodoInicial <= 71  && nodoInicial >= 65)
    {
        cout << "Nodo seleccionado: " << nodoInicial << endl << endl;
        graf ->algoritmoBellmanFord(nodoInicial);
    }
    else
    {
        cout << "Nodo seleccionado: S" << endl << endl;
        graf ->algoritmoBellmanFord('S');
    }

    delete graf;

    return 0;
}
