#include "arbol.h"
#include <iostream>

ArbolMedicos::ArbolMedicos() : raiz(nullptr) {}

ArbolMedicos::~ArbolMedicos() {
    destruirRec(raiz);
}

void ArbolMedicos::destruirRec(Nodo* nodo) {
    if (!nodo) return;
    destruirRec(nodo->izq);
    destruirRec(nodo->der);
    delete nodo;
}

void ArbolMedicos::insertarRec(Nodo*& nodo, const std::string& nombre, const std::string& esp) {
    if (!nodo) {
        nodo = new Nodo(nombre, esp);
    } else if (nombre < nodo->nombre) {
        insertarRec(nodo->izq, nombre, esp);
    } else {
        insertarRec(nodo->der, nombre, esp);
    }
}

void ArbolMedicos::agregarMedico(const std::string& nombre, const std::string& esp) {
    insertarRec(raiz, nombre, esp);
}

void ArbolMedicos::inordenRec(Nodo* nodo) const {
    if (!nodo) return;
    inordenRec(nodo->izq);
    std::cout << nodo->nombre << " | " << nodo->especialidad << "\n";
    inordenRec(nodo->der);
}

void ArbolMedicos::mostrarMedicos() const {
    std::cout << "\n--- Médicos (orden alfabético) ---\n";
    inordenRec(raiz);
    std::cout << "----------------------------------\n";
}

// Aliases para compatibilidad
void ArbolMedicos::insertar(const std::string& nombre, const std::string& esp) {
    agregarMedico(nombre, esp);
}

void ArbolMedicos::mostrar() const {
    mostrarMedicos();
}
