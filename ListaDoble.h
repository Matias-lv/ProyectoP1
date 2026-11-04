#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <functional>
#include "Nodo.h"

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble();
    ~ListaDoble();
    bool estaVacia();
    Nodo<T>* getCabeza();
    void insertar(T dato);
    void mostrar(std::function<void(T)> imprimir);
    Nodo<T>* buscar(std::function<bool(T)> criterio);
    bool eliminar(std::function<bool(T)> criterio);
};

#include "ListaDoble.cpp"

#endif