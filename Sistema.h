/***********************************************************************
 * Module:  Sistema.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:32:51
 * Purpose: Declaration of the class Sistema
 ***********************************************************************/

#if !defined(__RegistroDocente_Sistema_h)
#define __RegistroDocente_Sistema_h

class ListaDoble;

class Sistema
{
public:
   void ingresarDocente(void);
   void ingresarMateria(void);
   void asignarMateria(void);
   void registrarAsistencia(void);
   Sistema();
   ~Sistema();

   ListaDoble* listas[3];

protected:
private:
   ListaDoble<Profesor> profesores;
   ListaDoble<Materia> materias;
   ListaDoble<Registro> registros;


};

#endif