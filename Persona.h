#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
private:
    std::string cedula;
    std::string nombre;
    std::string apellido;
    std::string segundoNombre;
    std::string segundoApellido;
    std::string correo;
public:
    Persona();
    virtual ~Persona();
    std::string getCedula();
    void setCedula(std::string newCedula);
    std::string getNombre();
    void setNombre(std::string newNombre);
    std::string getApellido();
    void setApellido(std::string newApellido);
    std::string getSegundoNombre();
    void setSegundoNombre(std::string newSegundoNombre);
    std::string getSegundoApellido();
    void setSegundoApellido(std::string newSegundoApellido);
    std::string getCorreo();
    void setCorreo(std::string newCorreo);
};
#endif