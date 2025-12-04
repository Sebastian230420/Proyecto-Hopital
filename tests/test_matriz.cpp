/*
 * Archivo: tests/test_matriz.cpp
 * Descripción: Pruebas unitarias para la estructura Matriz (2D)
 * Cobertura: 6 pruebas unitarias
 */

#include "test_utils.h"
#include "../src/matriz.h"

/*
 * ============================================
 * PRUEBAS UNITARIAS - ESTRUCTURA MATRIZ
 * ============================================
 * 
 * La Matriz es una estructura bidimensional que representa
 * la disponibilidad de consultorios (3 pisos x 4 consultorios)
 * 
 * Valores:
 * - 0: LIBRE (consultorio disponible)
 * - 1: OCUPADO (consultorio en uso)
 * - -1: Coordinada inválida (fuera de rango)
 * 
 * Operaciones principales:
 * - get(int r, int c): Obtiene valor en [r][c]
 * - set(int r, int c, int val): Asigna valor en [r][c]
 * - mostrar(): Visualiza la matriz
 * - filasCount(), colsCount(): Retorna dimensiones
 * 
 * Importancia de validación de límites:
 * - Evita segmentation faults
 * - Previene corrupción de memoria
 * - Garantiza comportamiento predecible
 */

void testCrearMatriz() {
    /*
     * Prueba: Crear matriz con dimensiones específicas
     * Justificación: Constructor debe inicializar dimensiones
     * Acción: Crear Matriz(3, 4)
     * Resultado esperado: filasCount() == 3 && colsCount() == 4
     */
    Matriz matriz(3, 4);
    
    bool resultado = (matriz.filasCount() == 3) && (matriz.colsCount() == 4);
    ASSERT_TRUE(resultado, "Crear matriz 3x4");
}

void testGetInvalido() {
    /*
     * Prueba: get() retorna -1 para coordenadas inválidas
     * Justificación: Validación de límites previene acceso inválido
     * Acción: Llamar get(10, 10) en matriz 3x4
     * Resultado esperado: -1
     * 
     * Esta es una prueba de DEFENSA:
     * Verificamos que la estructura es segura contra
     * intentos de acceso fuera de rango
     */
    Matriz matriz(3, 4);
    int resultado = matriz.get(10, 10);
    ASSERT_EQUAL(resultado, -1, "get() retorna -1 para coordenadas inválidas");
}

void testGetValido() {
    /*
     * Prueba: get() retorna 0 o 1 para coordenadas válidas
     * Justificación: Validar que la matriz se inicializa con valores válidos
     * Acción: Llamar get(0, 0) en matriz recién creada
     * Resultado esperado: 0 o 1 (valores aleatorios en constructor)
     * 
     * Nota: La matriz se inicializa con valores aleatorios en el constructor
     * Por eso verificamos que sea 0 O 1, no un valor específico
     */
    Matriz matriz(3, 4);
    int valor = matriz.get(0, 0);
    
    bool resultado = (valor == 0) || (valor == 1);
    ASSERT_TRUE(resultado, "get() retorna 0 o 1 para coordenadas válidas");
}

void testSetValido() {
    /*
     * Prueba: set() cambia el valor correctamente
     * Justificación: Verificar que la modificación persiste
     * Acción: set(1, 1, 1), luego get(1, 1)
     * Resultado esperado: 1
     * 
     * Prueba de modificación exitosa:
     * Asignamos un valor y verificamos que se guardó
     */
    Matriz matriz(3, 4);
    matriz.set(1, 1, 1);
    int valor = matriz.get(1, 1);
    
    ASSERT_EQUAL(valor, 1, "set() cambia valor correctamente");
}

void testSetInvalido() {
    /*
     * Prueba: set() ignora coordenadas inválidas
     * Justificación: Prevenir acceso a memoria inválida
     * Acción: set(10, 10, 1), luego verificar get(10, 10)
     * Resultado esperado: -1 (indica inválido, no cambió)
     * 
     * Defensa contra intentos de escritura inválida:
     * set() debe ignorar silenciosamente coordenadas fuera de rango
     */
    Matriz matriz(3, 4);
    matriz.set(10, 10, 1);  // Intento inválido
    int valor = matriz.get(10, 10);
    
    ASSERT_EQUAL(valor, -1, "set() ignora coordenadas inválidas");
}

void testToggleEstado() {
    /*
     * Prueba: Toggle (cambio) de estado 0↔1
     * Justificación: Validar que la matriz puede cambiar estados
     * Acción: Obtener valor, cambiar a opuesto, verificar
     * Resultado esperado: El valor es el opuesto
     * 
     * Operación típica del sistema:
     * Cuando un consultorio pasa de LIBRE (0) a OCUPADO (1) o viceversa
     */
    Matriz matriz(3, 4);
    
    int inicial = matriz.get(0, 0);
    int opuesto = (inicial == 0) ? 1 : 0;
    
    matriz.set(0, 0, opuesto);
    int final = matriz.get(0, 0);
    
    ASSERT_EQUAL(final, opuesto, "Toggle estado consultorio (0→1 o 1→0)");
}

// Función para ejecutar todas las pruebas de Matriz
void ejecutarPruebasUnitariasMatriz() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PRUEBAS UNITARIAS: ESTRUCTURA MATRIZ (2D)\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "\nDescripción:\n";
    std::cout << "La Matriz representa la disponibilidad de consultorios.\n";
    std::cout << "Dimensiones: 3 pisos x 4 consultorios\n";
    std::cout << "Valores: 0=LIBRE, 1=OCUPADO, -1=Inválido\n";
    std::cout << "\nCaracterísticas:\n";
    std::cout << "  - Acceso O(1) a elementos\n";
    std::cout << "  - Validación de límites en get/set\n";
    std::cout << "  - Inicialización aleatoria\n";
    std::cout << "\n";
    
    testCrearMatriz();
    testGetInvalido();
    testGetValido();
    testSetValido();
    testSetInvalido();
    testToggleEstado();
    
    std::cout << "\n";
}
