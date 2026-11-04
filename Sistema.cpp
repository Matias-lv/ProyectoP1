#include "Sistema.h"
#include <iostream>
#include <ctime>
#include <cstdio>

const int NUM_FRANJAS = 7;
const int INICIO_FRANJA[NUM_FRANJAS] = {420, 540, 660, 780, 900, 1020, 1140};
const int DURACION = 120;
const int TOLERANCIA = 10;

Sistema::Sistema() {
    contadorRegistros = 0;
    minutosSimulados = -1;
}

Sistema::~Sistema() {
    registros.mostrar([](Registro* r) { delete r; });
    materias.mostrar([](Materia* m) { delete m; });
    profesores.mostrar([](Profesor* p) { delete p; });
}

// ---------- utilidades ----------
std::string Sistema::leerTexto(std::string mensaje) {
    std::string t;
    std::cout << mensaje;
    std::getline(std::cin, t);
    return t;
}

int Sistema::leerEntero(std::string mensaje) {
    while (true) {
        std::string t = leerTexto(mensaje);
        try { return std::stoi(t); }
        catch (...) { std::cout << "Valor invalido.\n"; }
    }
}

int Sistema::minutosActuales() {
    if (minutosSimulados >= 0) return minutosSimulados;
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    return ahora->tm_hour * 60 + ahora->tm_min;
}

std::string Sistema::fechaActual() {
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);
    char buf[11];
    strftime(buf, sizeof(buf), "%d/%m/%Y", ahora);
    return buf;
}

std::string Sistema::minutosAHora(int minutos) {
    char buf[6];
    snprintf(buf, sizeof(buf), "%02d:%02d", minutos / 60, minutos % 60);
    return buf;
}

void Sistema::mostrarFranjas() {
    for (int i = 0; i < NUM_FRANJAS; i++) {
        std::cout << "  Franja " << i + 1 << ": "
                  << minutosAHora(INICIO_FRANJA[i]) << " - "
                  << minutosAHora(INICIO_FRANJA[i] + DURACION) << "\n";
    }
}

Profesor* Sistema::buscarProfesor(std::string cedula) {
    Nodo<Profesor*>* n = profesores.buscar([&](Profesor* p) {
        return p->getCedula() == cedula;
    });
    return n ? n->getDato() : nullptr;
}

Materia* Sistema::buscarMateria(std::string nrc) {
    Nodo<Materia*>* n = materias.buscar([&](Materia* m) {
        return m->getNrc() == nrc;
    });
    return n ? n->getDato() : nullptr;
}

// Materia del profesor cuya ventana (inicio o fin +-10 min) esta abierta ahora
Materia* Sistema::materiaEnVentana(Profesor* p, bool entrada) {
    int ahora = minutosActuales();
    Nodo<Materia*>* n = p->getMaterias()->buscar([&](Materia* m) {
        int ref = INICIO_FRANJA[m->getFranja() - 1] + (entrada ? 0 : DURACION);
        return ahora >= ref - TOLERANCIA && ahora <= ref + TOLERANCIA;
    });
    return n ? n->getDato() : nullptr;
}

Registro* Sistema::buscarRegistroHoy(std::string cedula, std::string nrc, std::string fecha) {
    Nodo<Registro*>* n = registros.buscar([&](Registro* r) {
        return r->getCedula() == cedula && r->getNrc() == nrc && r->getFecha() == fecha;
    });
    return n ? n->getDato() : nullptr;
}

void Sistema::imprimirRegistro(Registro* r) {
    std::cout << "ID: " << r->getId()
              << " | Cedula: " << r->getCedula()
              << " | NRC: " << r->getNrc()
              << " | Fecha: " << r->getFecha()
              << " | Entrada: " << (r->getHoraEntrada().empty() ? "--:--" : r->getHoraEntrada())
              << " | Salida: " << (r->getHoraSalida().empty() ? "--:--" : r->getHoraSalida())
              << "\n";
}

// Imprime los registros de una cedula y devuelve cuantos hay
int Sistema::mostrarRegistrosDe(std::string cedula) {
    int cantidad = 0;
    registros.mostrar([&](Registro* r) {
        if (r->getCedula() == cedula) {
            imprimirRegistro(r);
            cantidad++;
        }
    });
    if (cantidad == 0) std::cout << "Esa cedula no tiene registros.\n";
    return cantidad;
}

// ---------- opciones del menu ----------
void Sistema::ingresarDocente() {
    std::string cedula = leerTexto("Cedula: ");
    if (cedula.empty()) { std::cout << "La cedula no puede estar vacia.\n"; return; }
    if (buscarProfesor(cedula) != nullptr) {
        std::cout << "Ya existe un docente con esa cedula.\n";
        return;
    }
    Profesor* p = new Profesor();
    p->setCedula(cedula);
    p->setNombre(leerTexto("Nombre: "));
    p->setApellido(leerTexto("Apellido: "));
    profesores.insertar(p);
    std::cout << "Docente ingresado.\n";
}

void Sistema::ingresarMateria() {
    std::string nrc = leerTexto("NRC: ");
    if (nrc.empty()) { std::cout << "El NRC no puede estar vacio.\n"; return; }
    if (buscarMateria(nrc) != nullptr) {
        std::cout << "Ya existe una materia con ese NRC.\n";
        return;
    }
    std::string nombre = leerTexto("Nombre de la materia: ");
    mostrarFranjas();
    int franja = leerEntero("Franja (1-7): ");
    if (franja < 1 || franja > NUM_FRANJAS) {
        std::cout << "Franja invalida.\n";
        return;
    }
    Materia* m = new Materia();
    m->setNrc(nrc);
    m->setNombre(nombre);
    m->setFranja(franja);
    materias.insertar(m);
    std::cout << "Materia ingresada.\n";
}

void Sistema::asignarMateria() {
    Profesor* p = buscarProfesor(leerTexto("Cedula del docente: "));
    if (p == nullptr) { std::cout << "Docente no encontrado.\n"; return; }

    bool hay = false;
    std::cout << "Materias disponibles:\n";
    materias.mostrar([&](Materia* m) {
        if (!m->getOcupado() && !p->tieneChoque(m->getFranja())) {
            int f = m->getFranja() - 1;
            std::cout << "  NRC: " << m->getNrc() << " | " << m->getNombre()
                      << " | " << minutosAHora(INICIO_FRANJA[f]) << " - "
                      << minutosAHora(INICIO_FRANJA[f] + DURACION) << "\n";
            hay = true;
        }
    });
    if (!hay) { std::cout << "No hay materias disponibles para este docente.\n"; return; }

    Materia* m = buscarMateria(leerTexto("NRC a asignar: "));
    if (m == nullptr || m->getOcupado() || p->tieneChoque(m->getFranja())) {
        std::cout << "NRC no valido o no disponible.\n";
        return;
    }
    p->asignarMateria(m);
    m->setOcupado(true);
    std::cout << "Materia asignada.\n";
}

void Sistema::registrarEntrada() {
    std::string cedula = leerTexto("Cedula: ");
    Profesor* p = buscarProfesor(cedula);
    if (p == nullptr) { std::cout << "Docente no encontrado.\n"; return; }

    Materia* m = materiaEnVentana(p, true);
    if (m == nullptr) { std::cout << "Fuera del horario de entrada.\n"; return; }

    std::string fecha = fechaActual();
    if (buscarRegistroHoy(cedula, m->getNrc(), fecha) != nullptr) {
        std::cout << "La entrada de esta materia ya esta registrada.\n";
        return;
    }

    Nodo<Registro*>* pendiente = registros.buscar([&](Registro* r) {
        return r->getCedula() == cedula && r->getFecha() == fecha && r->getHoraSalida().empty();
    });
    if (pendiente != nullptr) {
        std::cout << "No puede registrar entrada: falta la salida de la materia NRC "
                  << pendiente->getDato()->getNrc() << ".\n";
        return;
    }

    Registro* r = new Registro();
    r->setId(std::to_string(++contadorRegistros));
    r->setCedula(cedula);
    r->setNrc(m->getNrc());
    r->setFecha(fecha);
    r->setHoraEntrada(minutosAHora(minutosActuales()));
    registros.insertar(r);
    std::cout << "Entrada registrada: " << m->getNombre() << " a las "
              << r->getHoraEntrada() << ".\n";
}

void Sistema::registrarSalida() {
    std::string cedula = leerTexto("Cedula: ");
    Profesor* p = buscarProfesor(cedula);
    if (p == nullptr) { std::cout << "Docente no encontrado.\n"; return; }

    Materia* m = materiaEnVentana(p, false);
    if (m == nullptr) { std::cout << "Fuera del horario de salida.\n"; return; }

    Registro* r = buscarRegistroHoy(cedula, m->getNrc(), fechaActual());
    if (r == nullptr) {
        std::cout << "No tiene entrada registrada para esta materia.\n";
        return;
    }
    if (!r->getHoraSalida().empty()) {
        std::cout << "La salida de esta materia ya esta registrada.\n";
        return;
    }
    r->setHoraSalida(minutosAHora(minutosActuales()));
    std::cout << "Salida registrada: " << m->getNombre() << " a las "
              << r->getHoraSalida() << ".\n";
}

void Sistema::buscarRegistro() {
    mostrarRegistrosDe(leerTexto("Cedula del docente: "));
}

void Sistema::mostrarRegistros() {
    if (registros.estaVacia()) { std::cout << "No hay registros.\n"; return; }
    registros.mostrar([&](Registro* r) { imprimirRegistro(r); });
}

void Sistema::eliminarRegistro() {
    std::string cedula = leerTexto("Cedula del docente: ");
    if (mostrarRegistrosDe(cedula) == 0) return;

    std::string id = leerTexto("ID del registro a eliminar: ");
    Nodo<Registro*>* n = registros.buscar([&](Registro* r) {
        return r->getId() == id && r->getCedula() == cedula;
    });
    if (n == nullptr) { std::cout << "ID no valido para esa cedula.\n"; return; }

    Registro* r = n->getDato();
    registros.eliminar([&](Registro* x) { return x == r; });
    delete r;
    std::cout << "Registro eliminado.\n";
}

// Solo para pruebas: permite probar las ventanas de 6:50 a 7:10, etc.
void Sistema::simularHora() {
    int h = leerEntero("Hora (0-23, -1 para volver a la hora real): ");
    if (h < 0) {
        minutosSimulados = -1;
        std::cout << "Usando la hora real.\n";
        return;
    }
    int min = leerEntero("Minutos (0-59): ");
    if (h > 23 || min < 0 || min > 59) { std::cout << "Hora invalida.\n"; return; }
    minutosSimulados = h * 60 + min;
    std::cout << "Hora simulada: " << minutosAHora(minutosSimulados) << "\n";
}

void Sistema::menu() {
    int opcion;
    do {
        std::cout << "\n===== REGISTRO DE DOCENTES =====\n"
                  << "1. Ingresar docente\n"
                  << "2. Ingresar materia\n"
                  << "3. Asignar materia a docente\n"
                  << "4. Registrar entrada\n"
                  << "5. Registrar salida\n"
                  << "6. Buscar registros\n"
                  << "7. Mostrar registros\n"
                  << "8. Eliminar registro\n"
                  << "9. Simular hora (pruebas)\n"
                  << "0. Salir\n";
        opcion = leerEntero("Opcion: ");
        switch (opcion) {
            case 1: ingresarDocente(); break;
            case 2: ingresarMateria(); break;
            case 3: asignarMateria(); break;
            case 4: registrarEntrada(); break;
            case 5: registrarSalida(); break;
            case 6: buscarRegistro(); break;
            case 7: mostrarRegistros(); break;
            case 8: eliminarRegistro(); break;
            case 9: simularHora(); break;
            case 0: std::cout << "Hasta luego.\n"; break;
            default: std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}