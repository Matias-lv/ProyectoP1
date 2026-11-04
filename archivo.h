#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "ListaDoble.h"
#include "Profesor.h"
#include "Materia.h"
#include "Registro.h"



//   docentes.txt      cedula#nombre#apellido
//   materias.txt      nrc#nombre#franja
//   asignaciones.txt  cedula#nrc
//   registros.txt     id#cedula#nrc#fecha#horaEntrada#horaSalida
class Archivo {
public:
    static void guardarProfesores(ListaDoble<Profesor*>& profesores);
    static void guardarMaterias(ListaDoble<Materia*>& materias);
    static void guardarAsignaciones(ListaDoble<Profesor*>& profesores);
    static void guardarRegistros(ListaDoble<Registro*>& registros);

    static void cargarProfesores(ListaDoble<Profesor*>& profesores);
    static void cargarMaterias(ListaDoble<Materia*>& materias, int numFranjas);
    static void cargarAsignaciones(ListaDoble<Profesor*>& profesores,ListaDoble<Materia*>& materias);
    static void cargarRegistros(ListaDoble<Registro*>& registros);
};

#endif