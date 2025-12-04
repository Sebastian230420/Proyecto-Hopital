#ifndef EXTENSION_H
#define EXTENSION_H

#include <iostream>
#include <limits>
#include <string>

// Lectura segura de enteros
inline int leerEnteroSeguro(const std::string& prompt="> ") {
    int x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) break;
        std::cout << "Entrada inválida. Intente de nuevo.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return x;
}

// Lectura de línea de texto
inline std::string leerLinea(const std::string& prompt="") {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

// Función para mostrar un paciente (si no quieres repetir código)
inline void mostrarPacienteSimple(int id, const std::string& nombre, const std::string& area) {
    std::cout << "ID: " << id << " | Nombre: " << nombre << " | Área: " << area << "\n";
}

#endif // EXTENSION_H
