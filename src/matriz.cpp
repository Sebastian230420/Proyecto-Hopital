#include "matriz.h"
#include <cstdlib>
#include <iomanip>
#include <string>

// Constructor: inicializa matriz con valores 0 o 1 aleatorios
Matriz::Matriz(int f, int c) : filas(f), cols(c) {
    datos.assign(filas, std::vector<int>(cols, 0));
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < cols; ++j)
            datos[i][j] = rand() % 2;
}

// Cambiar valor en fila r, columna c
void Matriz::set(int r, int c, int val) {
    if (r >= 0 && r < filas && c >= 0 && c < cols)
        datos[r][c] = val;
}

// Obtener valor en fila r, columna c
int Matriz::get(int r, int c) const {
    if (r >= 0 && r < filas && c >= 0 && c < cols)
        return datos[r][c];
    return -1; // coordenada inválida
}

// Mostrar la matriz
void Matriz::mostrar() const {
    const int ancho = 15; // Ancho fijo para cada columna
    
    std::cout << "\n=== ESTADO DE CONSULTORIOS DEL HOSPITAL ===\n\n";
    
    // Encabezado con números de consultorio
    std::cout << std::setw(10) << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(ancho) << "Consultorio " + std::to_string(j + 1);
    }
    std::cout << "\n";
    
    // Línea separadora
    std::cout << std::setw(10) << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(ancho) << "---------------";
    }
    std::cout << "\n";
    
    // Contenido de la matriz
    for (int i = 0; i < filas; ++i) {
        std::cout << "Piso " << (i + 1) << "   │";
        for (int j = 0; j < cols; ++j) {
            std::string estado = datos[i][j] == 0 ? "LIBRE" : "OCUPADO";
            std::cout << std::setw(ancho) << estado;
        }
        std::cout << "\n";
    }
    
    // Línea separadora final
    std::cout << std::setw(8) << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << std::setw(ancho) << "------------";
    }
    std::cout << "\n\n";
    
    // Leyenda
    std::cout << "Leyenda:\n";
    std::cout << "- LIBRE: Consultorio disponible\n";
    std::cout << "- OCUPADO: Consultorio en uso\n";
}
