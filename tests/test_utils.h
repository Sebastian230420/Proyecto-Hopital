/*
 * Archivo: tests/test_utils.h
 * Descripción: Utilidades comunes para todas las pruebas unitarias
 * Incluye: Macros de assertion, reportes, y funciones auxiliares
 */

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <iostream>
#include <string>
#include <vector>

// Variables globales de estadísticas
extern int totalPruebas;
extern int pruebasExitosas;
extern int pruebasFallidas;

// Estructura para guardar resultados de pruebas
struct ResultadoPrueba {
    std::string nombre;
    bool exitosa;
    std::string mensaje;
};

// Vector global de resultados
extern std::vector<ResultadoPrueba> resultados;

// Macros para assertions
#define ASSERT_TRUE(condicion, nombre) \
    do { \
        if (condicion) { \
            reportarExito(nombre); \
        } else { \
            reportarFallo(nombre, "La condición es falsa"); \
        } \
    } while(0)

#define ASSERT_FALSE(condicion, nombre) \
    do { \
        if (!(condicion)) { \
            reportarExito(nombre); \
        } else { \
            reportarFallo(nombre, "La condición es verdadera"); \
        } \
    } while(0)

#define ASSERT_EQUAL(actual, esperado, nombre) \
    do { \
        if ((actual) == (esperado)) { \
            reportarExito(nombre); \
        } else { \
            reportarFallo(nombre, "Valor no coincide"); \
        } \
    } while(0)

#define ASSERT_NOT_NULL(ptr, nombre) \
    do { \
        if ((ptr) != nullptr) { \
            reportarExito(nombre); \
        } else { \
            reportarFallo(nombre, "Puntero es nullptr"); \
        } \
    } while(0)

#define ASSERT_NULL(ptr, nombre) \
    do { \
        if ((ptr) == nullptr) { \
            reportarExito(nombre); \
        } else { \
            reportarFallo(nombre, "Puntero no es nullptr"); \
        } \
    } while(0)

// Funciones de utilidad
void reportarExito(const std::string& nombre);
void reportarFallo(const std::string& nombre, const std::string& razon);
void inicializarEstadisticas();
void mostrarResumenPruebas();
void mostrarDetallesPruebas();

#endif // TEST_UTILS_H
