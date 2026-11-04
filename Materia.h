/***********************************************************************
 * Module:  Materia.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:35:25
 * Purpose: Declaration of the class Materia
 ***********************************************************************/

#if !defined(__RegistroDocente_Materia_h)
#define __RegistroDocente_Materia_h

class Materia
{
public:
   Materia();
   ~Materia();
   std::string getNrc(void);
   void setNrc(std::string newNrc);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   int getFranja(void);
   void setFranja(int newFranja);
   bool getOcupado(void);
   void setOcupado(bool newOcupado);

protected:
private:
   std::string nrc;
   std::string nombre;
   int franja;
   bool ocupado;


};

#endif