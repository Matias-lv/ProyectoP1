#include "Nodo.h"
template <typename T>
Nodo<T>::Nodo(T dato) {
    this->dato = dato;
    siguiente = nullptr;
    anterior = nullptr;
}

template <typename T>
Nodo<T>::~Nodo() {}

template <typename T>
T Nodo<T>::getDato() { return dato; }

template <typename T>
void Nodo<T>::setDato(T newDato) { dato = newDato; }

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() { return siguiente; }

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* newSiguiente) { siguiente = newSiguiente; }

template <typename T>
Nodo<T>* Nodo<T>::getAnterior() { return anterior; }

template <typename T>
void Nodo<T>::setAnterior(Nodo<T>* newAnterior) { anterior = newAnterior; }