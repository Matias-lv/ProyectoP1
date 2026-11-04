/***********************************************************************
 * Module:  Profesor.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:41:16
 * Purpose: Declaration of the class Profesor
 ***********************************************************************/

#if !defined(__RegistroDocente_Profesor_h)
#define __RegistroDocente_Profesor_h

class Materia;

#include <Persona.h>
#include <Materia.h>

class Profesor : public Persona
{
public:
   Profesor();
   ~Profesor();
   void asignarMateria(Materia* materia);
   bool tieneChoque(int franja);
   ListaDoble<Materia*>* getMaterias(void);

   Materia** materiasAsignadas;

protected:
private:
   ListaDoble<Materia*> materias;


};

#endif