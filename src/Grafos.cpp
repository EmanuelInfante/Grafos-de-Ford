#include <iostream>
#include <string>
#include <limits>
#include "Grafos.h"


using namespace std;


struct Distancias
{
    Nodos *nodoDestino;
    Nodos *nodoAnterior;
    int distancia;

};


Grafos::Grafos()
{
    //Constructor que realiza el grafos solicitado por la UNA
    //Los nodos solicitados son A, B, C, D, E, F, G, S

    this ->cantidadNodos = 8;
    this ->nodos = NULL;

    this ->crearNodosDefecto();

}


Grafos::~Grafos()
{
    //dtor
}


void Grafos::algoritmoBellmanFord(char nombreNodo)
{
    // Algoritmo de belmanFOrd

    Distancias **distanciasAnterior = this ->inicializarValoresAlgoritmoFord(nombreNodo);
    Distancias **distanciasActual = this ->inicializarValoresAlgoritmoFord(nombreNodo);
    // Recorremos las listas, revisamos la lista 1, y si hay alguna distancia mejorable, se mejora
    do
    {
       for(int i = 0; i < this ->cantidadNodos; i++)
        {
            // Si es el nodo inicial, continuamos
            if(distanciasActual[i] ->distancia == 0)
                continue;
            for(int j = 0; j < this ->cantidadNodos; j++)
            {
                if(distanciasActual[j] ->distancia == numeric_limits<int>::max())
                    continue;
                int costoAux = this ->nodos ->obtenerCostoNodos(distanciasAnterior[j] ->nodoDestino ->getNombreNodo(), distanciasActual[i] ->nodoDestino ->getNombreNodo());

                if(costoAux +distanciasActual[j] ->distancia < distanciasActual[i] ->distancia && costoAux != numeric_limits<int>::max())
                {
                    if(distanciasActual[i] ->distancia == numeric_limits<int>::max())
                        distanciasActual[i] ->distancia = costoAux +distanciasActual[j] ->distancia;
                    else
                        distanciasActual[i] ->distancia = costoAux + distanciasActual[j] ->distancia;
                    distanciasActual[i] ->nodoAnterior = distanciasAnterior[j] ->nodoDestino;
                }
            }

        }

    }while(this ->continuarAlgoritmo(distanciasAnterior, distanciasActual));

    for(int i = 0; i < this ->cantidadNodos; i++)
        cout << distanciasActual[i] ->nodoDestino ->getNombreNodo() << ") " << distanciasActual[i] ->nodoAnterior ->getNombreNodo() << " " <<  " " << distanciasActual[i] ->distancia << endl;



}


//.------------------------------MÉTODOS PRIVADOS--------------------------
bool Grafos::continuarAlgoritmo(Distancias **distanciasAnterior, Distancias **distanciasActual)
{
    // Método que retorna true si el algoritmo debe continuar, false en caso contrario. Además igual la distancia antigua con la actual
    bool valorRetorno;

    for(int i = 0; i < this ->cantidadNodos; i++)
    {
        if(distanciasActual[i] ->distancia != distanciasAnterior[i] ->distancia || distanciasActual[i] ->nodoAnterior != distanciasAnterior[i] ->nodoAnterior || distanciasActual[i] ->nodoDestino != distanciasAnterior[i] ->nodoDestino)
        {
            valorRetorno = true;
            break;
        }
        else
            valorRetorno = false;
    }

    for(int i = 0; i < this ->cantidadNodos; i++)
    {
        distanciasAnterior[i] ->distancia = distanciasActual[i] ->distancia;
        distanciasAnterior[i] ->nodoAnterior = distanciasActual[i] ->nodoAnterior;
        distanciasAnterior[i] ->nodoDestino = distanciasActual[i] ->nodoDestino;

    }

    return valorRetorno;

}


Distancias** Grafos::inicializarValoresAlgoritmoFord(char nombreNodo)
{
    // Creamos los valores en la estructura, e inicializamos el algoritmo en INFINITO y 0

    Distancias **distancias = new Distancias*[this ->cantidadNodos];
    Nodos *nodoAux = this ->nodos;

    for(int i = 0; i < this ->cantidadNodos; i++)
    {

        distancias[i] = new Distancias;

        if(nodoAux ->getNombreNodo() == nombreNodo)
        {
            distancias[i] ->distancia = 0;
        }
        else
        {
            distancias[i] ->distancia = numeric_limits<int>::max();
        }
        distancias[i] ->nodoAnterior = this ->nodos ->obtenerNodo(nombreNodo);
        distancias[i] ->nodoDestino = nodoAux ->obtenerNodo();
        nodoAux = nodoAux ->getSiguienteNodo();
    }

    return distancias;

}



void Grafos::crearNodosDefecto()
{
    // Fúnción que crea solicita la creación de los arcos, pasando los dados por la UNA

    /*Esta variable guarda cada uno de los nodos, y los nodos a los que apunta, teniendo
    Además los valores de su arco de por medio*/
    string nombresNodosArcos[11][8] = {{ "A", "B", "C", "D", "E", "F", "G", "S" },
                                    { "5", "12", "6", "1", "5", "8", "1", "6" },
                                    { "E", "A", "S", "B", "A", "C", "E", "B" },
                                    { "12", "9", "4", "4", "9", "3", "4", "8" },
                                    { "B", "E", "D", "E", "B", "D", "F", "D" },
                                    { "", "1", "8", "3", "4", "2", "", "6" },
                                    { "", "D", "F", "F", "D", "E", "", "C" },
                                    { "", "6", "", "4", "2", "4", "", "" },
                                    { "", "S", "", "C", "F", "G", "", "" },
                                    { "", "", "", "8", "1", "", "", "" },
                                    { "", "", "", "S", "G", "", "", "" },
                                    };

    // Creamos los nodos
    for(int i = 0; i < this ->cantidadNodos; i++)
    {
        if(this ->nodos == NULL)
            this ->nodos = new Nodos(*nombresNodosArcos[0][i].c_str());
        else
            this ->nodos ->agregarNodo(*nombresNodosArcos[0][i].c_str());
    }


    //Creamos ciclo para agregar arcos
    for(int i = 0; i < this ->cantidadNodos; i++)
    {
        // Le asignamos los "Arcos"
        for(int j = 1; j <= 10; j+=2)
        {
            // Agregamos los nodos y/o arcos
            if(nombresNodosArcos[j][i] != "")
            {

                this ->nodos ->agregarArco(*nombresNodosArcos[0][i].c_str(), *nombresNodosArcos[j+1][i].c_str(), int(stoi(nombresNodosArcos[j][i])));
            }

            else
                break;
        }
    }

}
