#include "Materia.h"

Materia::Materia() { franja = 0; ocupado = false; }
Materia::~Materia() {}
std::string Materia::getNrc() { return nrc; }
void Materia::setNrc(std::string newNrc) { nrc = newNrc; }
std::string Materia::getNombre() { return nombre; }
void Materia::setNombre(std::string newNombre) { nombre = newNombre; }
int Materia::getFranja() { return franja; }
void Materia::setFranja(int newFranja) { franja = newFranja; }
bool Materia::getOcupado() { return ocupado; }
void Materia::setOcupado(bool newOcupado) { ocupado = newOcupado; }