#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include "ListaDoble.h"
#include "Profesor.h"
#include "Materia.h"
#include "Registro.h"

class Sistema {
private:
    ListaDoble<Profesor*> profesores;
    ListaDoble<Materia*> materias;
    ListaDoble<Registro*> registros;
    int contadorRegistros;
    int minutosSimulados;
   std::string textoFranja(int franja);

    std::string leerTexto(std::string mensaje);
    int leerEntero(std::string mensaje);
    int minutosActuales();
    std::string fechaActual();
    std::string minutosAHora(int minutos);
    void mostrarFranjas();
    Profesor* buscarProfesor(std::string cedula);
    std::string generarCorreo(Profesor* p);
    Materia* buscarMateria(std::string nrc);
    Materia* materiaEnVentana(Profesor* p, bool entrada);
    Registro* buscarRegistroHoy(std::string cedula, std::string nrc, std::string fecha);
    void imprimirRegistro(Registro* r);
    int mostrarRegistrosDe(std::string cedula);

public:
    Sistema();
    ~Sistema();
    void ingresarDocente();
    void ingresarMateria();
    void asignarMateria();
    void registrarEntrada();
    void registrarSalida();
    void buscarRegistro();
    void mostrarDocentes();
    void mostrarMaterias();
    void mostrarRegistros();
    void eliminarRegistro();
    void simularHora();
    void menu();
};
#endif