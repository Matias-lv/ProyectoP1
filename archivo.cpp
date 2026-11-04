#include "archivo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

void Archivo::guardarProfesores(ListaDoble<Profesor*>& profesores) {
    std::ofstream f("docentes.txt");
    if (!f) { std::cout << "No se pudo guardar docentes.txt\n"; return; }
    profesores.mostrar([&](Profesor* p) {
        f << p->getCedula() << "#"<< p->getNombre() << "#"<< p->getSegundoNombre() << "#"<< p->getApellido() << "#"<< p->getSegundoApellido() << "#"<< p->getCorreo() << "\n";
    });
}

void Archivo::guardarMaterias(ListaDoble<Materia*>& materias) {
    std::ofstream f("materias.txt");
    if (!f) { std::cout << "No se pudo guardar materias.txt\n"; return; }
    materias.mostrar([&](Materia* m) {
        f << m->getNrc() << "#" << m->getNombre() << "#" << m->getFranja() << "\n";
    });
}

void Archivo::guardarAsignaciones(ListaDoble<Profesor*>& profesores) {
    std::ofstream f("asignaciones.txt");
    if (!f) { std::cout << "No se pudo guardar asignaciones.txt\n"; return; }
    profesores.mostrar([&](Profesor* p) {
        std::string cedula = p->getCedula();
        p->getMaterias()->mostrar([&](Materia* m) {
            f << cedula << "#" << m->getNrc() << "\n";
        });
    });
}

void Archivo::guardarRegistros(ListaDoble<Registro*>& registros) {
    std::ofstream f("registros.txt");
    if (!f) { std::cout << "No se pudo guardar registros.txt\n"; return; }
    registros.mostrar([&](Registro* r) {
        f << r->getId() << "#" << r->getCedula() << "#" << r->getNrc() << "#"
          << r->getFecha() << "#" << r->getHoraEntrada() << "#" << r->getHoraSalida() << "\n";
    });
}

void Archivo::cargarProfesores(ListaDoble<Profesor*>& profesores) {
    std::ifstream f("docentes.txt");
    std::string linea;
    while (std::getline(f, linea)) {
     
    std::stringstream ss(linea);
    std::string cedula, nombre, segNombre, apellido, segApellido, correo;
    std::getline(ss, cedula, '#');
    std::getline(ss, nombre, '#');
    std::getline(ss, segNombre, '#');
    std::getline(ss, apellido, '#');
    std::getline(ss, segApellido, '#');
    std::getline(ss, correo, '#');
        if (cedula.empty()) continue;
         if (apellido.empty()) {
        apellido = segNombre;
        segNombre = "";
    }
        Profesor* p = new Profesor();
        p->setCedula(cedula);
        p->setNombre(nombre);
        p->setApellido(apellido);
        p->setSegundoNombre(segNombre);
        p->setSegundoApellido(segApellido);
        p->setCorreo(correo);
        profesores.insertar(p);
    }
}

void Archivo::cargarMaterias(ListaDoble<Materia*>& materias, int numFranjas) {
    std::ifstream f("materias.txt");
    std::string linea;
    while (std::getline(f, linea)) {
        std::stringstream ss(linea);
        std::string nrc, nombre, franjaTexto;
        std::getline(ss, nrc, '#');
        std::getline(ss, nombre, '#');
        std::getline(ss, franjaTexto, '#');
        int franja = atoi(franjaTexto.c_str());
        // una franja fuera de 1..numFranjas haria que el programa falle al usarla
        if (nrc.empty() || franja < 1 || franja > numFranjas) continue;

        Materia* m = new Materia();
        m->setNrc(nrc);
        m->setNombre(nombre);
        m->setFranja(franja);
        materias.insertar(m);
    }
}

void Archivo::cargarAsignaciones(ListaDoble<Profesor*>& profesores,
                                 ListaDoble<Materia*>& materias) {
    std::ifstream f("asignaciones.txt");
    std::string linea;
    while (std::getline(f, linea)) {
        std::stringstream ss(linea);
        std::string cedula, nrc;
        std::getline(ss, cedula, '#');
        std::getline(ss, nrc, '#');

        Nodo<Profesor*>* np = profesores.buscar([&](Profesor* p) { return p->getCedula() == cedula; });
        Nodo<Materia*>* nm = materias.buscar([&](Materia* m) { return m->getNrc() == nrc; });
        if (np == nullptr || nm == nullptr) continue;   // docente o materia no existe

        np->getDato()->asignarMateria(nm->getDato());
        nm->getDato()->setOcupado(true);                // ocupado se deduce de la asignacion
    }
}

void Archivo::cargarRegistros(ListaDoble<Registro*>& registros) {
    std::ifstream f("registros.txt");
    std::string linea;
    while (std::getline(f, linea)) {
        std::stringstream ss(linea);
        std::string id, cedula, nrc, fecha, entrada, salida;
        std::getline(ss, id, '#');
        std::getline(ss, cedula, '#');
        std::getline(ss, nrc, '#');
        std::getline(ss, fecha, '#');
        std::getline(ss, entrada, '#');
        std::getline(ss, salida, '#');     // si la salida esta vacia, se queda vacia
        if (id.empty()) continue;

        Registro* r = new Registro();
        r->setId(id);
        r->setCedula(cedula);
        r->setNrc(nrc);
        r->setFecha(fecha);
        r->setHoraEntrada(entrada);
        r->setHoraSalida(salida);
        registros.insertar(r);
    }
}