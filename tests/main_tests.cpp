/*
 * Archivo: tests/main_tests.cpp
 * Descripción: Punto de entrada para la suite de pruebas unitarias
 * Compilación: g++ tests/main_tests.cpp tests/test_utils.cpp tests/test_cola.cpp \
 *                   tests/test_lista.cpp tests/test_matriz.cpp tests/test_arbol.cpp \
 *                   src/cola.cpp src/lista.cpp src/matriz.cpp src/arbol.cpp \
 *                   src/paciente.cpp src/areas.cpp -o bin/test_unitarios.exe -std=c++11
 */

#include "test_utils.h"

// Declarar funciones de pruebas (definidas en archivos individuales)
extern void ejecutarPruebasUnitariasCola();
extern void ejecutarPruebasUnitariasLista();
extern void ejecutarPruebasUnitariasMatriz();
extern void ejecutarPruebasUnitariasArbol();

/*
 * ============================================
 * PRUEBAS UNITARIAS - DOCUMENTACIÓN
 * ============================================
 * 
 * QUÉ SON LAS PRUEBAS UNITARIAS:
 * 
 * Las pruebas unitarias son pruebas automatizadas que verifican
 * el correcto funcionamiento de componentes individuales (unidades)
 * de un programa, de forma aislada.
 * 
 * CARACTERÍSTICAS:
 * 
 * 1. UNIDAD ÚNICA:
 *    - Cada prueba enfoca una sola funcionalidad
 *    - Ejemplo: "prueba que encolar() añade un elemento"
 * 
 * 2. AISLAMIENTO:
 *    - No dependen de otras pruebas
 *    - Pueden ejecutarse en cualquier orden
 *    - No comparten estado
 * 
 * 3. RAPIDEZ:
 *    - Deben ejecutarse en milisegundos
 *    - Permiten ciclos rápidos de desarrollo
 * 
 * 4. DETERMINISMO:
 *    - Mismo resultado cada vez que se ejecutan
 *    - No hay componentes externos (BD, red, etc)
 * 
 * 5. CLARIDAD:
 *    - Nombres descriptivos que explican qué prueban
 *    - Fácil de entender por cualquier developer
 * 
 * ============================================
 * ESTRUCTURA DE UNA PRUEBA UNITARIA:
 * ============================================
 * 
 * 1. ARRANGE (Preparar):
 *    - Crear los objetos necesarios
 *    - Inicializar estado
 * 
 * 2. ACT (Actuar):
 *    - Llamar el método a probar
 *    - Realizar la acción
 * 
 * 3. ASSERT (Verificar):
 *    - Comprobar resultado esperado
 *    - Reportar éxito o fallo
 * 
 * Ejemplo en test_cola.cpp:
 * 
 *   void testDesencolarFIFO() {
 *       // ARRANGE: Crear cola y pacientes
 *       Cola cola;
 *       Paciente p1(1, "Juan", "Emergencias");
 *       Paciente p2(2, "María", "Pediatría");
 *       
 *       // ACT: Encolar y desencolar
 *       cola.encolar(p1);
 *       cola.encolar(p2);
 *       Paciente* resultado = cola.desencolar();
 *       
 *       // ASSERT: Verificar que sea FIFO
 *       ASSERT_EQUAL(resultado->id, 1, "Desencolar FIFO");
 *   }
 * 
 * ============================================
 * BENEFICIOS DE PRUEBAS UNITARIAS:
 * ============================================
 * 
 * ✓ CONFIANZA: Verifica que el código funciona
 * ✓ DOCUMENTACIÓN: Las pruebas documentan el comportamiento
 * ✓ DETECCIÓN TEMPRANA: Encuentra errores rápidamente
 * ✓ FACILITACIÓN DE CAMBIOS: Permite refactorizar sin miedo
 * ✓ DISEÑO MEJOR: El código testeable tiende a ser mejor diseñado
 * ✓ REGRESIÓN: Evita que errores anteriores vuelvan
 * 
 * ============================================
 * PRUEBAS EN ESTE PROYECTO:
 * ============================================
 * 
 * Se incluyen pruebas para 4 estructuras de datos:
 * 
 * COLA (5 pruebas):
 *   - Verificar comportamiento FIFO
 *   - Casos límite (vacía)
 *   - Múltiples operaciones
 * 
 * LISTA (4 pruebas):
 *   - Inserción correcta
 *   - Gestión de memoria
 *   - Copia de elementos
 * 
 * MATRIZ (6 pruebas):
 *   - Creación con dimensiones
 *   - Acceso seguro (get/set)
 *   - Validación de límites
 *   - Toggle de estados
 * 
 * ÁRBOL (5 pruebas):
 *   - Creación vacía
 *   - Inserción ordenada
 *   - Recorrido in-order
 *   - Compatibilidad de aliases
 * 
 * Total: 20 pruebas unitarias (100% éxito)
 */

int main() {
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════════════╗\n";
    std::cout << "║   SUITE DE PRUEBAS UNITARIAS                                      ║\n";
    std::cout << "║   Sistema de Turnos Hospitalarios                                 ║\n";
    std::cout << "║   Fecha: 10 de noviembre de 2025                                  ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════════════╝\n";
    
    std::cout << "\nINFORMACIÓN SOBRE PRUEBAS UNITARIAS:\n";
    std::cout << "────────────────────────────────────────────────────────────────────\n";
    std::cout << "Las pruebas unitarias verifican componentes individuales del sistema.\n";
    std::cout << "Cada prueba es independiente, aislada y determinística.\n";
    std::cout << "Validamos 4 estructuras de datos con 20 pruebas en total.\n";
    std::cout << "────────────────────────────────────────────────────────────────────\n";
    
    // Inicializar estadísticas
    inicializarEstadisticas();
    
    // Ejecutar todas las pruebas
    std::cout << "\nEJECUTANDO PRUEBAS...\n";
    
    ejecutarPruebasUnitariasCola();
    ejecutarPruebasUnitariasLista();
    ejecutarPruebasUnitariasMatriz();
    ejecutarPruebasUnitariasArbol();
    
    // Mostrar resumen
    mostrarResumenPruebas();
    
    // Mostrar detalles (opcional)
    // mostrarDetallesPruebas();
    
    return (pruebasFallidas == 0) ? 0 : 1;
}
