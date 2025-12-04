#include "hospital.h"
#include <iostream>

Hospital::Hospital() : idPaciente(1), consultorios(3,4) {
    // Áreas precargadas
    areas.agregar("Emergencias");
    areas.agregar("Pediatría");
    areas.agregar("Cardiología");
    areas.agregar("Dermatología");

    // Médicos precargados
    medicos.agregarMedico("Gomez, Ana", "Cardiología");
    medicos.agregarMedico("Perez, Luis", "Pediatría");
    medicos.agregarMedico("Lopez, Carla", "Dermatología");
    medicos.agregarMedico("Zambrano, Mario", "Emergencias");
}

void Hospital::menu() {
    int opcion;
    do {
        std::cout << "\n=== SISTEMA DE TURNOS HOSPITALARIOS ===\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Mostrar pacientes en cola\n";
        std::cout << "3. Atender paciente\n";
        std::cout << "4. Mostrar historial de pacientes\n";
        std::cout << "5. Mostrar médicos\n";
        std::cout << "6. Consultorios (disponibilidad)\n";
        std::cout << "7. Toggle estado consultorio\n";
        std::cout << "0. Salir\n";
        std::cout << "> ";

        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion) {
            case 1: registrarPaciente(); break;
            case 2: mostrarPacientesEnCola(); break;
            case 3: atenderPaciente(); break;
            case 4: mostrarHistorial(); break;
            case 5: mostrarMedicos(); break;
            case 6: mostrarConsultorios(); break;
            case 7: toggleConsultorio(); break;
            case 0: std::cout << "Saliendo...\n"; break;
            default: std::cout << "Opción inválida.\n";
        }

    } while(opcion != 0);
}

void Hospital::registrarPaciente() {
    std::string nombre;
    std::cout << "Ingrese nombre del paciente: ";
    std::getline(std::cin, nombre);

    int idx = seleccionarArea();
    std::string areaSel = areas.obtener(idx);

    Paciente p(idPaciente++, nombre, areaSel);
    colaTurnos.encolar(p);

    std::cout << "Paciente registrado: ID " << p.id << ", Área " << p.area << "\n";
}

void Hospital::mostrarPacientesEnCola() {
    colaTurnos.mostrar();
}

void Hospital::atenderPaciente() {
    if (colaTurnos.vacia()) {
        std::cout << "No hay pacientes en la cola.\n";
        return;
    }

    Paciente* p = colaTurnos.desencolar();
    std::cout << "Atendiendo paciente:\n";
    mostrarPaciente(*p);

    historial.insertar(p); // mueve paciente a historial (toma propiedad)
}

void Hospital::mostrarHistorial() {
    historial.mostrar();
}

void Hospital::mostrarMedicos() {
    medicos.mostrarMedicos();
}

void Hospital::mostrarConsultorios() {
    consultorios.mostrar();
}

void Hospital::toggleConsultorio() {
    mostrarConsultorios(); // Mostrar estado actual primero
    
    int r, c;
    std::cout << "\n╔═══════════════════════════════════════╗\n";
    std::cout << "║     CAMBIAR ESTADO DE CONSULTORIO     ║\n";
    std::cout << "╚═══════════════════════════════════════╝\n\n";
    
    std::cout << "Ingrese el número de piso (1 a " << consultorios.filasCount() << "): ";
    std::cin >> r;
    std::cout << "Ingrese el número de consultorio (1 a " << consultorios.colsCount() << "): ";
    std::cin >> c;
    std::cin.ignore();
    
    // Ajustar los números ingresados a índices de 0
    r--; c--;

    int val = consultorios.get(r,c);
    if (val == -1) {
        std::cout << "\n❌ Error: Coordenadas inválidas.\n";
        return;
    }
    
    consultorios.set(r,c, val==0 ? 1 : 0);
    std::cout << "\n✅ El consultorio ha sido " << (val==0 ? "OCUPADO" : "LIBERADO") << " exitosamente.\n";
}

int Hospital::seleccionarArea() {
    areas.mostrar();
    int opcion;
    std::cout << "Seleccione área (número): ";
    std::cin >> opcion;
    std::cin.ignore();
    return opcion-1;
}
