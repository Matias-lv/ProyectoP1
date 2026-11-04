#include "Persona.h"

Persona::Persona() {}
Persona::~Persona() {}
std::string Persona::getCedula() { return cedula; }
void Persona::setCedula(std::string newCedula) { cedula = newCedula; }
std::string Persona::getNombre() { return nombre; }
void Persona::setNombre(std::string newNombre) { nombre = newNombre; }
std::string Persona::getApellido() { return apellido; }
void Persona::setApellido(std::string newApellido) { apellido = newApellido; }