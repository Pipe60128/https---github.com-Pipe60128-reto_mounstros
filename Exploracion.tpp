#pragma once 
using namespace std;
#include "Exploracion.h"

//constructor
template <typename T>
Exploracion<T> :: Exploracion(): head(nullptr), n(0){}

//destructor
template <typename T>
Exploracion<T> :: ~Exploracion(){
    clear();
    cout<<"toDO"<<endl;
}

//check if list is empty
template <typename T>
bool Exploracion<T> :: empty() const {
    return n==0 || !head;
}

//print method
template <typename T>
void Exploracion<T> :: print() {
    if (empty()) {
        cout<< "lista vacia" << endl;
    } else {
        const Casilla<T>* current = head;
        cout<<"[";
        while (current) {
            if (current->hasMonster() == 1){
                cout<<" (MOUNSTRO) ";
            } else {
                cout<<" (NO MOUNSTRO) ";
            }
            cout<<"  "<<current->nombreCasilla<<" ==== "<<current->data<<"\n ==->";
            current = current->next;
        }
        cout<<"]"<<endl;
    }
}

//pushFront
template <typename T>
void Exploracion<T> :: pushBack(const T& value, const T& nombre, int probmounstro){
    Casilla<T>* newCasilla = new Casilla<T>(value, nombre, probmounstro);
    if (!head) {
        head = newCasilla;
    } else {
        Casilla<T>* current = head;
        while (current->next) {
            current = current-> next;
        }
        current->next = newCasilla;
    }
    ++n;

        
    
}

//pushBack method
template <typename T>
void Exploracion<T> :: pushFront(const T& value, const T& nombre, int probmounstro ){
    Casilla<T>* newCasilla = new Casilla<T>(value, nombre, probmounstro);
    if (!head) {
        head = newCasilla;
    } else {
        newCasilla->next = head;
        head = newCasilla;
    }
    ++n;

}
 //inset method
template <typename T>
bool Exploracion<T> :: insert(unsigned int index, const T& value, const T& nombre, int probmounstro){
    if (index > n) return false;
    if (index == 0) {
        pushFront(value, nombre, probmounstro);
        return true;
    }
    Casilla<T>* current = head;
    for (unsigned int i = 0; i < index-1 && current; ++i){
        current = current->next;
    }
    if (!current) return false;
    Casilla<T>* newCasilla = new Casilla<T>(value, nombre, probmounstro);
    newCasilla->next = current->next;
    current->next = newCasilla;
    ++n;
    return true;

}
//remove method 
template <typename T>
bool Exploracion<T>::remove(const T& value) {
    if (empty()) return false;
    Casilla<T>* current = head;
    Casilla<T>* previous = nullptr;

    while (current) {
        if (current->data == value) {
            if (previous!= nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            --n;
            cout<<"first element with value "<< value<<" removed"<<endl;
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

//clear method
template <typename T>
void Exploracion<T> :: clear(){
    Casilla<T>* current = head;
    while (current){
        Casilla<T>* next = current->next;
        delete current;
        current = next;
        --n;
    }
    head = nullptr;
}

//size method
template <typename T> 
unsigned int Exploracion<T> :: size() const{
    unsigned int nSize = 0;
    Casilla<T>* current = head;
    while (current) {
        ++nSize;
        current = current -> next;
    }
    return nSize;

}

template <typename T>
T* Exploracion<T> :: elementAt( unsigned int index){
    if (empty()) return nullptr;
    Casilla<T>* current = head;
    unsigned int i = 0;
    while (current && i < index){
        current = current->next;
        ++i;
    }
    if (!current) return nullptr;
    return &(current->data);
}