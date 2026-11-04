#ifndef PROFESOR_H
#define PROFESOR_H
#include "Persona.h"
#include "Materia.h"
#include "ListaDoble.h"

class Profesor : public Persona {
private:
    ListaDoble<Materia*> materias;
public:
    Profesor();
    ~Profesor();
    ListaDoble<Materia*>* getMaterias();
    void asignarMateria(Materia* materia);
    bool tieneChoque(int franja);
};
#endif