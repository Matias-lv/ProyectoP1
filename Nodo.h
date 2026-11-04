#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    Nodo(T dato);
    ~Nodo();
    T getDato();
    void setDato(T newDato);
    Nodo<T>* getSiguiente();
    void setSiguiente(Nodo<T>* newSiguiente);
    Nodo<T>* getAnterior();
    void setAnterior(Nodo<T>* newAnterior);
};

#include "Nodo.cpp"

#endif