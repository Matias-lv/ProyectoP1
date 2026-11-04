/***********************************************************************
 * Module:  Nodo.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:47:21
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__RegistroDocente_Nodo_h)
#define __RegistroDocente_Nodo_h

class Nodo
{
public:
   Nodo(T dato);
   ~Nodo();
   T getDato(void);
   void setDato(T newDato);
   Nodo* getSiguiente_(void);
   void setSiguiente_(Nodo* newSiguiente_);
   Nodo* getAnterior(void);
   void setAnterior(Nodo* newAnterior);

protected:
private:
   T dato;
   Nodo* siguiente_;
   Nodo* anterior;


};

#endif