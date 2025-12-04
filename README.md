# Sistema de Gestión Hospitalaria

Este es un sistema de gestión hospitalaria basado en una aplicación de consola, desarrollado en C++. Permite administrar el flujo de pacientes, la disponibilidad de consultorios y el personal médico de manera eficiente.

## ✨ Características

- **Registro de Pacientes**: Añade nuevos pacientes a una cola de espera, asignándoles un área médica.
- **Gestión de Cola de Turnos**: Administra la fila de pacientes utilizando una estructura de cola (FIFO).
- **Historial de Pacientes**: Mantiene un registro de los pacientes que han sido atendidos en una lista enlazada.
- **Gestión de Consultorios**: Visualiza y actualiza el estado (Libre/Ocupado) de los consultorios usando una matriz.
- **Directorio de Médicos**: Organiza al personal médico en un árbol binario para búsquedas eficientes.
- **Interfaz de Consola Interactiva**: Un menú sencillo para navegar por todas las funcionalidades del sistema.

## 🛠️ Estructuras de Datos Implementadas

El núcleo del sistema se basa en las siguientes estructuras de datos implementadas desde cero:

- **Cola (`Cola`)**: Para la gestión de la fila de espera de pacientes.
- **Lista Enlazada (`Lista`)**: Para almacenar el historial de pacientes atendidos.
- **Matriz (`Matriz`)**: Para representar la disponibilidad de los consultorios.
- **Árbol Binario de Búsqueda (`Arbol`)**: Para organizar y buscar médicos por nombre.

## 📂 Estructura Detallada del Proyecto

A continuación se detalla el propósito de cada archivo y directorio dentro del proyecto:

```
ProyectoHospital/
├── .vscode/
│   ├── settings.json       # Configuraciones de VS Code para el espacio de trabajo.
│   └── tasks.json          # Define tareas como compilar y ejecutar para VS Code.
├── bin/
│   ├── ProyectoHospital.exe # Ejecutable principal de la aplicación.
│   └── test_unitarios.exe   # Ejecutable para correr las pruebas unitarias.
├── src/
│   ├── main.cpp            # Punto de entrada de la aplicación. Inicia el sistema y muestra el menú.
│   ├── hospital.h          # Define la clase 'Hospital' que centraliza toda la lógica.
│   ├── hospital.cpp        # Implementa los métodos de la clase 'Hospital'.
│   ├── paciente.h          # Define la estructura 'Paciente' y funciones relacionadas.
│   ├── paciente.cpp        # Implementa las funciones para manipular pacientes.
│   ├── areas.h             # Define la clase 'Areas' para gestionar las especialidades médicas.
│   ├── areas.cpp           # Implementa los métodos de la clase 'Areas'.
│   ├── cola.h              # Define la estructura de datos 'Cola' para la lista de espera.
│   ├── cola.cpp            # Implementa la lógica de la cola (encolar, desencolar, etc.).
│   ├── lista.h             # Define la 'Lista' enlazada para el historial de pacientes.
│   ├── lista.cpp           # Implementa la lógica de la lista (insertar, mostrar).
│   ├── arbol.h             # Define el 'Arbol' binario de búsqueda para el directorio de médicos.
│   ├── arbol.cpp           # Implementa la lógica del árbol (insertar, recorrer).
│   ├── matriz.h            # Define la 'Matriz' para representar los consultorios.
│   ├── matriz.cpp          # Implementa la lógica de la matriz (marcar ocupado/libre).
│   └── extension.h         # Contiene funciones de utilidad (helpers) para leer datos del usuario de forma segura.
├── tests/
│   ├── main_tests.cpp      # Punto de entrada que ejecuta todas las pruebas unitarias.
│   ├── test_arbol.cpp      # Pruebas específicas para la estructura de datos del árbol.
│   ├── test_cola.cpp       # Pruebas específicas para la estructura de datos de la cola.
│   ├── test_lista.cpp      # Pruebas específicas para la estructura de datos de la lista.
│   ├── test_matriz.cpp     # Pruebas específicas para la estructura de datos de la matriz.
│   ├── test_utils.h        # Define macros y funciones de utilidad para las pruebas (assertions).
│   ├── test_utils.cpp      # Implementa las funciones de utilidad para las pruebas.
│   └── README.md           # Documentación detallada del módulo de pruebas.
├── ISIL.docx               # Documento de Word, posiblemente relacionado con la institución educativa ISIL.
├── Makefile                # Script que automatiza la compilación del proyecto usando 'make'.
└── README.md               # Este archivo, con la documentación principal del proyecto.
```

## 🚀 Cómo Empezar

Sigue estas instrucciones para compilar y ejecutar el proyecto en tu máquina local.

### Prerrequisitos

Asegúrate de tener un compilador de C++ y `make` instalados.
- **g++**: `sudo apt-get install build-essential` en sistemas Debian/Ubuntu.
- **make**: Generalmente incluido en `build-essential`.

### Compilación

1.  Clona o descarga el repositorio.
2.  Abre una terminal en la raíz del proyecto.
3.  Ejecuta el siguiente comando para compilar la aplicación principal:

    ```sh
    make
    ```
    Esto compilará el código fuente y creará el ejecutable `hospital` (o `hospital.exe` en Windows) en la raíz del proyecto. Para moverlo a la carpeta `bin`, puedes hacerlo manualmente.

### Ejecución

Para iniciar el sistema de gestión hospitalaria, ejecuta el siguiente comando desde la raíz del proyecto:

```sh
./hospital
```
O en Windows:
```sh
hospital.exe
```

## 🧪 Ejecución de Pruebas

El proyecto incluye un conjunto de pruebas unitarias para validar el correcto funcionamiento de las estructuras de datos.

### Compilación de Pruebas

Usa el siguiente comando para compilar el ejecutable de las pruebas:

```sh
g++ -std=c++17 -Wall -Isrc -o bin/test_unitarios tests/*.cpp src/*.cpp
```

### Ejecutar las Pruebas

Una vez compilado, ejecuta las pruebas con:

```sh
./bin/test_unitarios
```
O en Windows:
```sh
.\bin\test_unitarios.exe
```

Todas las pruebas deberían pasar, confirmando que las estructuras de datos funcionan como se espera.
