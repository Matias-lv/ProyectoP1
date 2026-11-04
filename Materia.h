#ifndef MATERIA_H
#define MATERIA_H
#include <string>

class Materia {
private:
    std::string nrc;
    std::string nombre;
    int franja;
    bool ocupado;
public:
    Materia();
    ~Materia();
    std::string getNrc();
    void setNrc(std::string newNrc);
    std::string getNombre();
    void setNombre(std::string newNombre);
    int getFranja();
    void setFranja(int newFranja);
    bool getOcupado();
    void setOcupado(bool newOcupado);
};
#endif