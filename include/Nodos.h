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
        //int obtenerCostoNodo(char nodo);
        Nodos *obtenerNodo(char nombreNodo);
        //const Nodos *obtenerNodo(char nombreNodo) const ;

        //Métodos set
        void setNombreNodo(char nombreNodo) { this ->nombreNodo = nombreNodo; };

        void setAristaAdyacente(Arista *aristaAdyacente) { this ->aristaAdyacente = aristaAdyacente; };

        //Métodos get
        char getNombreNodo() { return this ->nombreNodo; };
        Nodos* obtenerNodo() { return this; };
        //const Nodos* obtenerNodo() const { return this; };
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
