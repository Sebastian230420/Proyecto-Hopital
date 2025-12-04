# Suite de Pruebas Unitarias del Sistema Hospitalario

Este documento detalla la suite de pruebas automatizadas diseñadas para garantizar la calidad y el correcto funcionamiento de cada componente del **Sistema de Turnos Hospitalarios**.

El enfoque de testing es **modular**, lo que significa que cada estructura de datos fundamental del proyecto se prueba de forma aislada para asegurar su fiabilidad antes de integrarla en el sistema principal.

---

## 1. Tipo de Pruebas Realizadas

Todas las pruebas en esta suite son **Pruebas Unitarias**.

*   **¿Qué es una Prueba Unitaria?** Es una prueba automática que se enfoca en verificar una única "unidad" o pieza de código (como una función o un método de una clase) de manera aislada.
*   **Objetivo**: Asegurar que cada componente individual funciona exactamente como se espera antes de combinarlo con otros.
*   **Ventajas**: Permiten detectar errores de forma temprana, facilitan la depuración (porque sabes exactamente qué falló) y sirven como una documentación viva del comportamiento del código.

---

## 2. Framework de Pruebas: `test_utils`

Para mantener la consistencia y la claridad, se utiliza un pequeño framework de aserciones definido en `test_utils.h` y `test_utils.cpp`. Este proporciona macros simples para verificar los resultados de las pruebas.

| Macro de Aserción | Propósito |
| :--- | :--- |
| `ASSERT_TRUE(cond, msg)` | Verifica que una condición sea **verdadera**. |
| `ASSERT_FALSE(cond, msg)` | Verifica que una condición sea **falsa**. |
| `ASSERT_EQUAL(val1, val2, msg)` | Verifica que dos valores sean **iguales**. |
| `ASSERT_NULL(ptr, msg)` | Verifica que un puntero sea **nulo** (`nullptr`). |
| `ASSERT_NOT_NULL(ptr, msg)` | Verifica que un puntero **no sea nulo**. |

---

## 3. Detalle de Pruebas por Módulo

A continuación se desglosan todas las pruebas realizadas para cada estructura de datos.

### Pruebas para `Cola` (Archivo: `test_cola.cpp`)
**Objetivo General**: Garantizar que la cola de turnos se comporte correctamente siguiendo el principio **FIFO** (First-In, First-Out).

| Prueba Ejecutada | Tipo de Prueba | Objetivo Específico | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| `testColaVaciaAlCrear` | Unitaria | Verificar que una cola recién creada esté vacía. | La llamada a `cola.vacia()` debe devolver `true`. |
| `testEncolarPaciente` | Unitaria | Asegurar que tras añadir un paciente, la cola ya no está vacía. | La llamada a `cola.vacia()` debe devolver `false`. |
| `testDesencolarFIFO` | Unitaria | Validar que al desencolar se obtiene el primer paciente que fue añadido. | El `id` del paciente devuelto debe ser el del primer paciente encolado. |
| `testDesencolarVacia` | Unitaria | Probar que intentar desencolar en una cola vacía no produce un error y devuelve un puntero nulo. | El resultado de `cola.desencolar()` debe ser `nullptr`. |
| `testMultiplesEncolares`| Unitaria | Confirmar que el orden FIFO se mantiene después de varias operaciones de encolar y desencolar. | Los pacientes deben ser atendidos en el mismo orden en que se registraron. |

### Pruebas para `Lista` (Archivo: `test_lista.cpp`)
**Objetivo General**: Validar que el historial de pacientes (implementado con una lista enlazada) funcione correctamente, especialmente en la inserción de nuevos registros.

| Prueba Ejecutada | Tipo de Prueba | Objetivo Específico | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| `testListaVaciaAlCrear` | Unitaria | Verificar que un historial recién creado esté vacío. | La llamada a `lista.vacia()` debe devolver `true`. |
| `testInsertarPaciente` | Unitaria | Asegurar que tras añadir un paciente al historial, la lista ya no está vacía. | La llamada a `lista.vacia()` debe devolver `false`. |
| `testMultiplesInserciones`| Unitaria | Probar que se pueden realizar múltiples inserciones sin errores de memoria. | El programa no debe fallar y la lista debe contener todos los elementos. |
| `testInsertarCopia` | Unitaria | Validar que se puede insertar una copia de un paciente, manteniendo el original intacto. | La lista contiene una nueva copia, y el objeto original no se ve afectado. |

### Pruebas para `Matriz` (Archivo: `test_matriz.cpp`)
**Objetivo General**: Asegurar que la representación de los consultorios en la matriz 2D sea precisa y que las operaciones de consulta y modificación de estado sean seguras.

| Prueba Ejecutada | Tipo de Prueba | Objetivo Específico | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| `testCrearMatriz` | Unitaria | Verificar que la matriz se inicializa con las dimensiones correctas (pisos y consultorios). | Las dimensiones de la matriz deben coincidir con las especificadas en el constructor. |
| `testGetInvalido` | Unitaria | Asegurar que intentar acceder a una coordenada fuera de los límites no falle y devuelva un código de error. | La llamada a `matriz.get()` con coordenadas inválidas debe devolver `-1`. |
| `testGetValido` | Unitaria | Probar que se puede obtener el estado (0 o 1) de un consultorio con coordenadas válidas. | El valor devuelto debe ser `0` (LIBRE) o `1` (OCUPADO). |
| `testSetValido` | Unitaria | Validar que se puede cambiar el estado de un consultorio usando coordenadas válidas. | El nuevo estado del consultorio debe reflejarse en la matriz. |
| `testSetInvalido` | Unitaria | Asegurar que un intento de cambiar el estado con coordenadas inválidas sea ignorado y no afecte la matriz. | La matriz no debe sufrir ninguna modificación. |
| `testToggleEstado` | Unitaria | Verificar que el estado de un consultorio se pueda alternar correctamente (de 0 a 1 y de 1 a 0). | Si el estado era `0`, debe cambiar a `1`, y viceversa. |

### Pruebas para `Arbol` (Archivo: `test_arbol.cpp`)
**Objetivo General**: Garantizar que el árbol binario de búsqueda (usado para los médicos) inserte y ordene los nodos correctamente para permitir búsquedas eficientes.

| Prueba Ejecutada | Tipo de Prueba | Objetivo Específico | Resultado Esperado |
| :--- | :--- | :--- | :--- |
| `testCrearArbolVacio` | Unitaria | Verificar que se pueda crear un árbol vacío sin errores. | El puntero a la raíz del árbol debe ser `nullptr`. |
| `testAgregarMedico` | Unitaria | Asegurar que se puede insertar un nuevo médico en el árbol. | El árbol ya no debe estar vacío después de la inserción. |
| `testAgregar4Medicos` | Unitaria | Probar que el árbol mantiene su estructura y orden después de múltiples inserciones. | Todas las inserciones se completan sin errores y los nodos se ubican correctamente. |
| `testMostrarMedicos` | Unitaria | Validar que el recorrido "in-order" del árbol muestra los médicos en orden alfabético. | La salida en consola debe mostrar los nombres de los médicos ordenados alfabéticamente. |
| `testAliases` | Unitaria | Confirmar que los métodos con nombres alternativos (alias) funcionan igual que los originales. | `insertar()` debe funcionar exactamente igual que `agregarMedico()`. |

---

## 4. Cómo Compilar y Ejecutar las Pruebas

Para verificar el proyecto, puedes compilar y ejecutar esta suite de pruebas.

**1. Comando de Compilación:**
Abre una terminal en la raíz del proyecto y ejecuta el siguiente comando. Este enlazará todos los archivos de prueba con las implementaciones necesarias de la carpeta `src`.

```bash
g++ tests/main_tests.cpp tests/test_utils.cpp tests/test_cola.cpp tests/test_lista.cpp tests/test_matriz.cpp tests/test_arbol.cpp src/cola.cpp src/lista.cpp src/matriz.cpp src/arbol.cpp src/paciente.cpp src/areas.cpp -o bin/test_unitarios.exe -std=c++11
```

**2. Ejecución de las Pruebas:**
Una vez compilado, ejecuta el archivo generado:

```bash
./bin/test_unitarios.exe
```

### Resultado Final Esperado

La ejecución de las pruebas mostrará un resumen en la consola. El resultado esperado es que **todas las pruebas pasen exitosamente**.

```
════════════════════════════════════════════════════════════════════════
RESUMEN DE PRUEBAS
════════════════════════════════════════════════════════════════════════
Total de pruebas:    20
Pruebas exitosas:    20 ✓
Pruebas fallidas:    0 ✗
Tasa de éxito:       100%
════════════════════════════════════════════════════════════════════════
```

Un resultado del 100% de éxito demuestra que todos los componentes básicos del sistema son **confiables, robustos y funcionan según lo diseñado**.