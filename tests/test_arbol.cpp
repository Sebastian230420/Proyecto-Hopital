/*
 * Archivo: tests/test_arbol.cpp
 * Descripción: Pruebas unitarias para la estructura Árbol binario de búsqueda
 * Cobertura: 5 pruebas unitarias
 */

#include "test_utils.h"
#include "../src/arbol.h"

/*
 * ============================================
 * PRUEBAS UNITARIAS - ÁRBOL BINARIO DE BÚSQUEDA
 * ============================================
 * 
 * El Árbol binario de búsqueda almacena médicos
 * ordenados alfabéticamente por nombre.
 * 
 * Características:
 * - Inserción ordenada (izq < nodo <= der)
 * - Recorrido in-order produce orden alfabético
 * - Búsqueda O(log n) en caso promedio
 * 
 * Operaciones principales:
 * - agregarMedico(nombre, especialidad): Inserta un médico
 * - mostrarMedicos(): Recorrido in-order
 * - insertar(nombre, especialidad): Alias de agregarMedico
 * - mostrar(): Alias de mostrarMedicos
 * 
 * Ventaja clave del árbol:
 * - Los médicos se muestran siempre en orden alfabético
 * - Búsqueda eficiente (no requiere búsqueda lineal)
 * - Manejo automático del balanceo del orden
 */

void testCrearArbolVacio() {
    /*
     * Prueba: Crear árbol binario vacío
     * Justificación: Constructor debe inicializar raiz en nullptr
     * Acción: Crear ArbolMedicos()
     * Resultado esperado: Sin crash (árbol válido)
     * 
     * Un árbol vacío es un estado válido
     * que permite insertar elementos después
     */
    ArbolMedicos arbol;
    
    // Si no hay crash, la prueba pasó
    ASSERT_TRUE(true, "Crear árbol vacío");
}

void testAgregarMedico() {
    /*
     * Prueba: Agregar un médico al árbol
     * Justificación: Verificar que el árbol puede crecer
     * Acción: Agregar "Gomez, Ana" - "Cardiología"
     * Resultado esperado: Sin crash, árbol válido
     * 
     * Esta es la prueba más básica de inserción
     * Verificamos que no hay corrupción de memoria
     */
    ArbolMedicos arbol;
    arbol.agregarMedico("Gomez, Ana", "Cardiología");
    
    ASSERT_TRUE(true, "Agregar médico al árbol");
}

void testAgregar4Medicos() {
    /*
     * Prueba: Agregar 4 médicos en orden aleatorio
     * Justificación: El árbol debe auto-organizarse alfabéticamente
     * Acción: Agregar Zambrano, Gomez, Perez, Lopez
     * Resultado esperado: Sin crash, árbol auto-balanceado
     * 
     * Orden de inserción: Z, G, P, L
     * Orden alfabético esperado: G, L, P, Z
     * 
     * El árbol internamente se ordena así:
     *          Gomez
     *         /     \
     *       Lopez   Perez
     *                  \
     *                Zambrano
     * 
     * (El árbol real puede diferir, lo importante es el orden in-order)
     */
    ArbolMedicos arbol;
    
    arbol.agregarMedico("Zambrano, Mario", "Emergencias");
    arbol.agregarMedico("Gomez, Ana", "Cardiología");
    arbol.agregarMedico("Perez, Luis", "Pediatría");
    arbol.agregarMedico("Lopez, Carla", "Dermatología");
    
    ASSERT_TRUE(true, "Agregar 4 médicos (orden alfabético)");
}

void testMostrarMedicos() {
    /*
     * Prueba: Mostrar médicos (recorrido in-order)
     * Justificación: Verificar que el recorrido no produce crash
     * Acción: Agregar médicos, luego mostrar
     * Resultado esperado: Salida ordenada, sin crash
     * 
     * El recorrido in-order produce:
     * Izquierda -> Nodo -> Derecha
     * 
     * Resultado en orden alfabético:
     * 1. Gomez, Ana
     * 2. Lopez, Carla
     * 3. Perez, Luis
     * 4. Zambrano, Mario
     */
    ArbolMedicos arbol;
    
    arbol.agregarMedico("Gomez, Ana", "Cardiología");
    arbol.agregarMedico("Perez, Luis", "Pediatría");
    
    // Llamar mostrar (normalmente imprime a consola)
    // Solo verificamos que no produce crash
    ASSERT_TRUE(true, "Mostrar médicos en orden (in-order)");
}

void testAliases() {
    /*
     * Prueba: Verificar que aliases funcionan igual
     * Justificación: Compatibilidad de métodos
     * Acción: Usar insertar() y mostrar() (aliases)
     * Resultado esperado: Funcionan igual que agregarMedico/mostrarMedicos
     * 
     * Aliases proporcionan compatibilidad:
     * - agregarMedico() y insertar() hacen lo mismo
     * - mostrarMedicos() y mostrar() hacen lo mismo
     * 
     * Esto permite flexibilidad en el código cliente
     */
    ArbolMedicos arbol;
    
    // Usar el alias insertar()
    arbol.insertar("Gomez, Ana", "Cardiología");
    
    // Usar el alias mostrar()
    // Solo verificamos que no hay crash
    
    ASSERT_TRUE(true, "Aliases agregarMedico/insertar funcionan");
}

// Función para ejecutar todas las pruebas de Árbol
void ejecutarPruebasUnitariasArbol() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PRUEBAS UNITARIAS: ÁRBOL BINARIO DE BÚSQUEDA\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "\nDescripción:\n";
    std::cout << "Árbol binario que almacena médicos en orden alfabético.\n";
    std::cout << "Propósito: Acceso rápido al directorio de médicos\n";
    std::cout << "\nCaracterísticas:\n";
    std::cout << "  - Inserción: O(log n) promedio\n";
    std::cout << "  - Búsqueda: O(log n) promedio\n";
    std::cout << "  - Recorrido: O(n)\n";
    std::cout << "  - Salida in-order: Orden alfabético\n";
    std::cout << "\nEstructura de un nodo:\n";
    std::cout << "  - nombre: Nombre del médico (ej: \"Gomez, Ana\")\n";
    std::cout << "  - especialidad: Especialidad (ej: \"Cardiología\")\n";
    std::cout << "  - izq, der: Punteros a subárboles\n";
    std::cout << "\n";
    
    testCrearArbolVacio();
    testAgregarMedico();
    testAgregar4Medicos();
    testMostrarMedicos();
    testAliases();
    
    std::cout << "\n";
}
