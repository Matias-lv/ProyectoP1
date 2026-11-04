/***********************************************************************
 * Module:  ListaDoble.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:47:17
 * Purpose: Declaration of the class ListaDoble
 ***********************************************************************/

#if !defined(__RegistroDocente_ListaDoble_h)
#define __RegistroDocente_ListaDoble_h

class Nodo;

#include <Nodo.h>

class ListaDoble
{
public:
   void insertar(void);
   bool eliminar(void);
   Nodo* buscar(void);
   void mostrar(void);
   ListaDoble();
   ~ListaDoble();

   Nodo** nodos;

protected:
private:
   Nodo* cabeza;
   Nodo* cola;


};

#endif