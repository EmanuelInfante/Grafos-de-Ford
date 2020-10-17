#ifndef NODOS_H
#define NODOS_H

#include "Arista.h"


class Arista;

class Nodos
{
    public:
        Nodos(char nombreNodo);
        virtual ~Nodos();

        // Métodos
        void agregarNodo(char nombreNodo);
        void agregarArco(char nombreNodoI, char nombreNodoF, int costo);
        Nodos *obtenerNodo(char nombreNodo);


        //Métodos set
        void setNombreNodo(char nombreNodo) { this ->nombreNodo = nombreNodo; };
        void setAristaAdyacente(Arista *aristaAdyacente) { this ->aristaAdyacente = aristaAdyacente; };

        //Métodos get
        char getNombreNodo() { return this ->nombreNodo; };
        Nodos* obtenerNodo() { return this; };
        int obtenerCostoNodos(char nodoI, char nodoF);
        Arista *getAristaAdyacente() { return this ->aristaAdyacente; };
        Nodos *getSiguienteNodo() { return this ->siguienteNodo; };

    protected:
        char nombreNodo;
        // Se encarga de guardar un puntero a otro nodo, que está conectado es al primer nodo de la pila
        Nodos *siguienteNodo;
        //Puntero a la primera arista del Nodo
        Arista *aristaAdyacente;

    private:



};

#endif // NODOS_H
