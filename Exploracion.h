#ifndef EXPLORACION_H
#define EXPLORACION_H
#include "Casilla.h"


template<typename T>
class Exploracion{
    private:
        Casilla<T>* head;
        unsigned int n;
    public:
        Exploracion();
        ~Exploracion();
        unsigned int size() const;
        bool empty() const; 
        void clear();
        void pushFront(const T& value, const T& nombre, int probmounstro);
        void pushBack(const T& value, const T& nombre, int probmounstro);
        bool insert(unsigned int index, const T& value, const T& nombre, int probmounstro);
        bool remove( const T& value);
        T* elementAt(unsigned int index);
        void print();


};

#include "Exploracion.tpp"
#endif //EXPLORACION_H