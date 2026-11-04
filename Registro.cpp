#include "Registro.h"

Registro::Registro() {}
Registro::~Registro() {}
std::string Registro::getId() { return id; }
void Registro::setId(std::string newId) { id = newId; }
std::string Registro::getNrc() { return nrc; }
void Registro::setNrc(std::string newNrc) { nrc = newNrc; }
std::string Registro::getFecha() { return fecha; }
void Registro::setFecha(std::string newFecha) { fecha = newFecha; }
std::string Registro::getHoraEntrada() { return horaEntrada; }
void Registro::setHoraEntrada(std::string newHoraEntrada) { horaEntrada = newHoraEntrada; }
std::string Registro::getCedula() { return cedula; }
void Registro::setCedula(std::string newCedula) { cedula = newCedula; }
std::string Registro::getHoraSalida() { return horaSalida; }
void Registro::setHoraSalida(std::string newHoraSalida) { horaSalida = newHoraSalida; }