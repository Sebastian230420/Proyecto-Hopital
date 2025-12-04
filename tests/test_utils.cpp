/*
 * Archivo: tests/test_utils.cpp
 * Descripción: Implementación de utilidades comunes para pruebas
 */

#include "test_utils.h"
#include <iomanip>

// Inicializar variables globales
int totalPruebas = 0;
int pruebasExitosas = 0;
int pruebasFallidas = 0;
std::vector<ResultadoPrueba> resultados;

void reportarExito(const std::string& nombre) {
    totalPruebas++;
    pruebasExitosas++;
    resultados.push_back({nombre, true, ""});
    std::cout << "  ✓ " << nombre << "\n";
}

void reportarFallo(const std::string& nombre, const std::string& razon) {
    totalPruebas++;
    pruebasFallidas++;
    resultados.push_back({nombre, false, razon});
    std::cout << "  ✗ " << nombre << " - Razón: " << razon << "\n";
}

void inicializarEstadisticas() {
    totalPruebas = 0;
    pruebasExitosas = 0;
    pruebasFallidas = 0;
    resultados.clear();
}

void mostrarResumenPruebas() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "RESUMEN DE PRUEBAS\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "Total de pruebas:    " << totalPruebas << "\n";
    std::cout << "Pruebas exitosas:    " << pruebasExitosas << " ✓\n";
    std::cout << "Pruebas fallidas:    " << pruebasFallidas << " ✗\n";
    
    if (totalPruebas > 0) {
        int porcentaje = (pruebasExitosas * 100) / totalPruebas;
        std::cout << "Tasa de éxito:       " << porcentaje << "%\n";
    }
    std::cout << std::string(70, '=') << "\n";
}

void mostrarDetallesPruebas() {
    std::cout << "\n" << std::string(70, '-') << "\n";
    std::cout << "DETALLES DE PRUEBAS\n";
    std::cout << std::string(70, '-') << "\n";
    
    for (const auto& resultado : resultados) {
        if (resultado.exitosa) {
            std::cout << "✓ " << std::setw(50) << std::left << resultado.nombre;
            std::cout << "[EXITOSA]\n";
        } else {
            std::cout << "✗ " << std::setw(50) << std::left << resultado.nombre;
            std::cout << "[FALLIDA] - " << resultado.mensaje << "\n";
        }
    }
    std::cout << std::string(70, '-') << "\n";
}
