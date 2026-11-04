#include "Persona.h"

Persona::Persona() {}
Persona::~Persona() {}
std::string Persona::getCedula() { 
    return cedula; 
}
void Persona::setCedula(std::string newCedula) { 
    cedula = newCedula; 
}
std::string Persona::getNombre() { 
    return nombre; 
}
void Persona::setNombre(std::string newNombre) { 
    nombre = newNombre; 
}
std::string Persona::getApellido() { 
    return apellido; 
}
void Persona::setApellido(std::string newApellido) { 
    apellido = newApellido; 
}
std::string Persona::getSegundoNombre() { 
    return segundoNombre; 
}
void Persona::setSegundoNombre(std::string newSegundoNombre) { 
    segundoNombre = newSegundoNombre; 
}
std::string Persona::getSegundoApellido() { 
    return segundoApellido; 
}
void Persona::setSegundoApellido(std::string newSegundoApellido) { 
    segundoApellido = newSegundoApellido; 
}
std::string Persona::getCorreo() { 
    return correo; 
}
void Persona::setCorreo(std::string newCorreo) { 
    correo = newCorreo; 
}