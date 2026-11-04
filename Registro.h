/***********************************************************************
 * Module:  Registro.h
 * Author:  Personal
 * Modified: martes, 3 de noviembre de 2026 22:41:16
 * Purpose: Declaration of the class Registro
 ***********************************************************************/

#if !defined(__RegistroDocente_Registro_h)
#define __RegistroDocente_Registro_h

class Profesor;

class Registro
{
public:
   std::string getNrc(void);
   void setNrc(std::string newNrc);
   std::string getFecha(void);
   void setFecha(std::string newFecha);
   std::string getHoraEntrada(void);
   void setHoraEntrada(std::string newHoraEntrada);
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getHoraSalida(void);
   void setHoraSalida(std::string newHoraSalida);
   std::string getId(void);
   void setId(std::string newId);
   Registro();
   ~Registro();

   Profesor* profesor;

protected:
private:
   std::string id;
   std::string nrc;
   std::string fecha;
   std::string horaEntrada;
   std::string cedula;
   std::string horaSalida;


};

#endif