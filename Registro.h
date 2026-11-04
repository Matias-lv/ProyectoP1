#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>

class Registro {
private:
    std::string id;
    std::string nrc;
    std::string fecha;
    std::string horaEntrada;
    std::string cedula;
    std::string horaSalida;
public:
    Registro();
    ~Registro();
    std::string getId();
    void setId(std::string newId);
    std::string getNrc();
    void setNrc(std::string newNrc);
    std::string getFecha();
    void setFecha(std::string newFecha);
    std::string getHoraEntrada();
    void setHoraEntrada(std::string newHoraEntrada);
    std::string getCedula();
    void setCedula(std::string newCedula);
    std::string getHoraSalida();
    void setHoraSalida(std::string newHoraSalida);
};
#endif