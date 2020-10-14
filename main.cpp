#include <iostream>
#include "Grafos.h"

using namespace std;

int main()
{
    cout << "ALgoritmo Bellman Ford. Universidad Nacional ABierta" << endl;

    Grafos *graf = new Grafos();

    graf ->algoritmoBellmanFord('S');
    return 0;
}
