#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
private:
    std::string cedula;
    std::string nombre;
    std::string apellido;
public:
    Persona();
    virtual ~Persona();
    std::string getCedula();
    void setCedula(std::string newCedula);
    std::string getNombre();
    void setNombre(std::string newNombre);
    std::string getApellido();
    void setApellido(std::string newApellido);
};
#endif