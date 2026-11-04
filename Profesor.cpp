#include "Profesor.h"

Profesor::Profesor() {}
Profesor::~Profesor() {}

ListaDoble<Materia*>* Profesor::getMaterias() { return &materias; }

void Profesor::asignarMateria(Materia* materia) {
    materias.insertar(materia);
}

bool Profesor::tieneChoque(int franja) {
    return materias.buscar([franja](Materia* m) {
        return m->getFranja() == franja;
    }) != nullptr;
}