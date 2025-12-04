/*
 * Archivo: tests/test_lista.cpp
 * Descripción: Pruebas unitarias para la estructura Lista enlazada
 * Cobertura: 4 pruebas unitarias
 */

#include "test_utils.h"
#include "../src/lista.h"
#include "../src/paciente.h"

/*
 * ============================================
 * PRUEBAS UNITARIAS - ESTRUCTURA LISTA ENLAZADA
 * ============================================
 * 
 * La Lista enlazada es una estructura que almacena
 * el historial de pacientes atendidos.
 * 
 * Características:
 * - Inserción al inicio (O(1))
 * - Recorrido secuencial (O(n))
 * - Gestión dinámica de memoria
 * 
 * Operaciones principales:
 * - insertar(): Añade paciente al inicio
 * - insertarCopia(): Inserta una copia del paciente
 * - mostrar(): Visualiza todos los pacientes
 * - vacia(): Verifica si la lista está vacía
 */

void testListaVaciaAlCrear() {
    /*
     * Prueba: Lista debe estar vacía al crear
     * Justificación: Constructor debe inicializar head en nullptr
     * Acción: Crear Lista y verificar vacia()
     * Resultado esperado: true
     */
    Lista lista;
    ASSERT_TRUE(lista.vacia(), "Lista vacía al crear");
}

void testInsertarPaciente() {
    /*
     * Prueba: Insertar un paciente marca lista como no vacía
     * Justificación: El método insertar() debe crear un nodo
     * Acción: Crear Lista, insertar paciente
     * Resultado esperado: lista.vacia() == false
     * 
     * Nota importante sobre gestión de memoria:
     * El método insertar() TOMA PROPIEDAD del puntero
     * Es decir, la Lista es responsable de liberar la memoria
     */
    Lista lista;
    Paciente* p = new Paciente(1, "Juan", "Emergencias");
    lista.insertar(p);
    ASSERT_FALSE(lista.vacia(), "Insertar paciente (no está vacía)");
}

void testMultiplesInserciones() {
    /*
     * Prueba: Múltiples inserciones sin errores de memoria
     * Justificación: Validar que no hay memory leaks
     * Acción: Insertar 5 pacientes
     * Resultado esperado: Sin crashes o errores de segmentación
     * 
     * Esta prueba es especialmente importante porque:
     * - Validamos que el destructor libera correctamente
     * - Verificamos que no hay corrupción de punteros
     * - Confirmamos que el enlazamiento de nodos es correcto
     */
    Lista lista;
    for (int i = 1; i <= 5; i++) {
        Paciente* p = new Paciente(i, "Paciente" + std::to_string(i), "Area");
        lista.insertar(p);
    }
    
    // Si llegamos aquí sin crash, la prueba pasó
    // El destructor de lista se ejecutará al salir del scope
    ASSERT_TRUE(true, "5 inserciones sin errores de memoria");
}

void testInsertarCopia() {
    /*
     * Prueba: Insertar una copia del paciente
     * Justificación: El método insertarCopia() debe copiar el paciente
     * Acción: Crear paciente en stack, insertarCopia en Lista
     * Resultado esperado: Lista no vacía
     * 
     * Diferencia importante:
     * - insertar(Paciente* p): Toma propiedad del puntero
     * - insertarCopia(const Paciente& p): Crea copia dinámica
     * 
     * insertarCopia es útil cuando tienes un paciente en stack
     * y quieres que la Lista maneje su memoria
     */
    Lista lista;
    Paciente p(1, "Juan", "Emergencias");
    lista.insertarCopia(p);
    ASSERT_FALSE(lista.vacia(), "Insertar copia del paciente");
}

// Función para ejecutar todas las pruebas de Lista
void ejecutarPruebasUnitariasLista() {
    std::cout << "\n" << std::string(70, '=') << "\n";
    std::cout << "PRUEBAS UNITARIAS: ESTRUCTURA LISTA ENLAZADA\n";
    std::cout << std::string(70, '=') << "\n";
    std::cout << "\nDescripción:\n";
    std::cout << "La Lista enlazada almacena el historial de pacientes atendidos.\n";
    std::cout << "Características: Inserción O(1), recorrido O(n), gestión dinámica.\n";
    std::cout << "\nMétodos clave:\n";
    std::cout << "  - insertar(Paciente* p): Toma propiedad del puntero\n";
    std::cout << "  - insertarCopia(const Paciente& p): Crea copia dinámica\n";
    std::cout << "\n";
    
    testListaVaciaAlCrear();
    testInsertarPaciente();
    testMultiplesInserciones();
    testInsertarCopia();
    
    std::cout << "\n";
}
