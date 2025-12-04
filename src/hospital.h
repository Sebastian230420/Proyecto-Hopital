#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "areas.h"
#include "paciente.h"
#include "cola.h"
#include "lista.h"
#include "arbol.h"
#include "matriz.h"
#include <string>

class Hospital {
private:
    Areas areas;           // Áreas del hospital
    Cola colaTurnos;       // Cola de pacientes
    Lista historial;       // Pacientes atendidos
    ArbolMedicos medicos;  // Médicos del hospital
    Matriz consultorios;   // Disponibilidad de consultorios
    int idPaciente;        // Contador de IDs

public:
    Hospital();

    void menu();                 // Menú principal
    void registrarPaciente();
    void mostrarPacientesEnCola();
    void atenderPaciente();
    void mostrarHistorial();
    void mostrarMedicos();
    void mostrarConsultorios();
    void toggleConsultorio();
private:
    int seleccionarArea();
};

#endif // HOSPITAL_H
