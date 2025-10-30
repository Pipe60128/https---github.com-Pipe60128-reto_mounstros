#include <iostream>
using namespace std;
#include "Exploracion.h"


int main() {
    Exploracion<string> list; 
    list.pushBack("Casilla 1", "Inicio", 10);
    list.pushBack("Casilla 2", "Medio bajo ", 20);
    list.pushBack("Casilla 3",  "Medio", 30);
    list.pushBack("Casilla 4", "Medio alto", 50);
    list.pushBack("Casilla 5", "prefinal", 70);
    list.pushBack("Casilla 6", "Final", 98);
    list.print();
    return 0;
}
