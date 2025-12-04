#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
public:
    int id;
    std::string nombre;
    std::string area;
    Paciente* siguiente;

    Paciente(int _id = 0, const std::string& _nombre = "", const std::string& _area = "")
        : id(_id), nombre(_nombre), area(_area), siguiente(nullptr) {}

    Paciente(const Paciente& other)
        : id(other.id), nombre(other.nombre), area(other.area), siguiente(nullptr) {}
};

// Funciones auxiliares (implementadas en paciente.cpp)
void mostrarPaciente(const Paciente& p);
Paciente crearPaciente(int id, const std::string& nombre, const std::string& area);

#endif // PACIENTE_H
