#include "ListaDoble.h"
#include <functional>
template <typename T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template <typename T>
ListaDoble<T>::~ListaDoble() {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

template <typename T>
bool ListaDoble<T>::estaVacia() {
    return cabeza == nullptr;
}

template <typename T>
Nodo<T>* ListaDoble<T>::getCabeza() {
    return cabeza;
}

template <typename T>
void ListaDoble<T>::insertar(T dato) {
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        nuevo->setAnterior(cola);
        cola = nuevo;
    }
}

template <typename T>
void ListaDoble<T>::mostrar(std::function<void(T)> imprimir) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        imprimir(actual->getDato());
        actual = actual->getSiguiente();
    }
}

template <typename T>
Nodo<T>* ListaDoble<T>::buscar(std::function<bool(T)> criterio) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        if (criterio(actual->getDato())) return actual;
        actual = actual->getSiguiente();
    }
    return nullptr;
}

template <typename T>
bool ListaDoble<T>::eliminar(std::function<bool(T)> criterio) {
    Nodo<T>* actual = buscar(criterio);
    if (actual == nullptr) return false;

    Nodo<T>* ant = actual->getAnterior();
    Nodo<T>* sig = actual->getSiguiente();

    if (ant != nullptr) ant->setSiguiente(sig);
    else cabeza = sig;

    if (sig != nullptr) sig->setAnterior(ant);
    else cola = ant;

    delete actual;
    return true;
}