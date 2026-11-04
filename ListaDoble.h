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
    ListaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    ~ListaDoble() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
    }

    bool estaVacia() { return cabeza == nullptr; }

    Nodo<T>* getCabeza() { return cabeza; }

    void insertar(T dato) {
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

    void mostrar(std::function<void(T)> imprimir) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            imprimir(actual->getDato());
            actual = actual->getSiguiente();
        }
    }

    Nodo<T>* buscar(std::function<bool(T)> criterio) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (criterio(actual->getDato())) return actual;
            actual = actual->getSiguiente();
        }
        return nullptr;
    }

    bool eliminar(std::function<bool(T)> criterio) {
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
};

#endif