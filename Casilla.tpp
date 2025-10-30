#pragma once
#include <cstdlib>
#include <ctime>
#include "Casilla.h"

#include <iostream>
using namespace std;

template <typename T>
Casilla<T> :: Casilla(const T& v, const T& nombre, int probmounstro)
    : idCasilla(0), nombreCasilla(nombre), data(v), next(nullptr), probmounstro(probmounstro) {}

template <typename T>
int Casilla<T> :: hasMonster() const{
    srand(time(nullptr));
    int random = rand() % 100;
    int probabilidad = probmounstro ;
    if (random < probabilidad) {
        return 1; // Aparece un monstruo
    } else {
        return 0; // No aparece un monstruo
    }
}


