#include "paciente.h"
#include <iostream>

void mostrarPaciente(const Paciente& p) {
    std::cout << "ID: " << p.id 
              << " | Nombre: " << p.nombre 
              << " | Área: " << p.area 
              << std::endl;
}

Paciente crearPaciente(int id, const std::string& nombre, const std::string& area) {
    return Paciente(id, nombre, area);
}
