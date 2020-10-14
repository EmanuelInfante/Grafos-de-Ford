#ifndef ARCOS_H
#define ARCOS_H


class Arcos
{
    public:
        Arcos(char nodoInicial, char nodoFinal, int valorArco);
        virtual ~Arcos();

    protected:

    private:
        char nodoInicial;
        char nodoFinal;
        int valorArco;
};

#endif // ARCOS_H
