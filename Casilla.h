#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
class Casilla{
    private:
        int probmounstro; // probabilidad (0-100) de que aparezca un monstruo
        int idCasilla;
    public:
        T nombreCasilla;
        T data;
        Casilla* next; 
        Casilla(const T& v, const T& nombre, int probmounstro);
        // Devuelve true si al consultar esta casilla aparece un monstruo
        int hasMonster() const;
};

#include "Casilla.tpp"
#endif //NODE_H