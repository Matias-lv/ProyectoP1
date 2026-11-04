/***********************************************************************
 * Module:  Persona.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 18:08:29
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__RegistroDocente_Persona_h)
#define __RegistroDocente_Persona_h

class Persona
{
public:
   Persona();
   ~Persona();
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);

protected:
private:
   std::string cedula;
   std::string nombre;
   std::string apellido;


};

#endif