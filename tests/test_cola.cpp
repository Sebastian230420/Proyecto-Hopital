/*
 * Archivo: tests/test_cola.cpp
 * Descripción: Pruebas unitarias para la estructura Cola (FIFO)
 * Cobertura: 5 pruebas unitarias
 */

#include "test_utils.h"
#include "../src/cola.h"
#include "../src/paciente.h"

/*
 * ============================================
 * PRUEBAS UNITARIAS - ESTRUCTURA COLA
 * ============================================
 * 
 * La Cola es una estructura FIFO (First In, First Out)
 * utilizada para gestionar la fila de espera de pacientes.
 * 
 * Operaciones principales:
 * - encolar(): Añade un paciente al final de la cola
 * - desencolar(): Extrae el primer paciente (FIFO)
 * - vacia(): Verifica si la cola no tiene elementos
 * - mostrar(): Visualiza los pacientes en la cola
 */

void testColaVaciaAlCrear() {
    /*
     * Prueba: Cola debe estar vacía cuando se crea
     * Justificación: Constructor debe inicializar referencias a nullptr
     * Acción: Crear Cola y verificar vacia()
     * Resultado esperado: true
     */
    Cola cola;
    ASSERT_TRUE(cola.vacia(), "Cola vacía al crear");
}

void testEncolarPaciente() {
    /*
     * Prueba: Encolar un paciente marca la cola como no vacía
     * Justificación: El método encolar() debe enlazar el nodo
     * Acción: Crear Cola, encolar paciente
     * Resultado esperado: cola.vacia() == false
     */
    Cola cola;
    Paciente p(1, "Juan", "Emergencias");
    cola.encolar(p);
    ASSERT_FALSE(cola.vacia(), "Encolar un paciente (no está vacía)");
}

void testDesencolarFIFO() {
    /*
     * Prueba: Desencolar retorna el primer paciente (FIFO)
     * Justificación: La cola debe mantener orden FIFO (primero en entrar, primero en salir)
     * Acción: Encolar P1 y P2, luego desencolar
     * Resultado esperado: El primer paciente desenlazado es P1 (ID=1)
     */
    Cola cola;
    Paciente p1(1, "Juan", "Emergencias");
    Paciente p2(2, "María", "Pediatría");
    
    cola.encolar(p1);
    cola.encolar(p2);
    
    Paciente* desenlazado = cola.desencolar();
    
    bool resultado = (desenlazado != nullptr) && 
                    (desenlazado->id == 1) && 
                    (desenlazado->nombre == "Juan");
    
    ASSERT_TRUE(resultado, "Desencolar retorna primer paciente (FIFO)");
    
    if (desenlazado != nullptr) {
        delete desenlazado;
    }
}

void testDesencolarVacia() {
    /*
     * Prueba: Desencolar en cola vacía retorna nullptr
     * Justificación: No debe haber acceso a memoria inválida
     * Acción: Desencolar de cola vacía
     * Resultado esperado: nullptr
     */
    Cola cola;
    Paciente* resultado = cola.desencolar();
    ASSERT_NULL(resultado, "Desencolar en cola vacía retorna nullptr");
}

void testMultiplesEncolaresDesenlares() {
    /*
     * Prueba: Múltiples operaciones mantienen consistencia FIFO
     * Justificación: Validar que la estructura funciona con múltiples elementos
     * Acción: Encolar 5 pacientes, desencolar todos
     * Resultado esperado: Se desenlacen en orden 1,2,3,4,5
     */
    Cola cola;
    
    // Encolar 5 pacientes
    for (int i = 1; i <= 5; i++) {
        Paciente p(i, "Paciente" + std::to_string(i), "Area");
        cola.encolar(p);
    }
    
    // Verificar que se desenlacen en orden
    bool fifoValido = true;
    for (int i = 1; i <= 5; i++) {
        Paciente* p = cola.desencolar();
        if (p == nullptr || p->id != i) {
            fifoValido = false;
        }
        delete p;
    }
    
    ASSERT_TRUE(fifoValido, "5 encolares y desenlares mantienen FIFO");
}

// Función para ejecutar todas las pruebas de Cola
void ejecutarPruebasUnitariasCola() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PRUEBAS UNITARIAS: ESTRUCTURA COLA (FIFO)\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "\nDescripción:\n";
    std::cout << "La Cola es una estructura de datos FIFO que implementa una fila\n";
    std::cout << "de espera. Operaciones principales: encolar, desencolar, vacia.\n";
    std::cout << "Complejidad: O(1) para todas las operaciones.\n";
    std::cout << "\n";
    
    testColaVaciaAlCrear();
    testEncolarPaciente();
    testDesencolarFIFO();
    testDesencolarVacia();
    testMultiplesEncolaresDesenlares();
    
    std::cout << "\n";
}
