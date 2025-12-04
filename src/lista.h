#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"
#include <iostream>

class Lista {
private:
    struct Node {
        Paciente* p;
        Node* next;
        Node(Paciente* _p) : p(_p), next(nullptr) {}
    };
    Node* head;

public:
    Lista();
    ~Lista();

    // Inserta un paciente (toma propiedad del puntero)
    void insertar(Paciente* paciente);

    // Inserta una copia del paciente (no transfiere propiedad)
    void insertarCopia(const Paciente& paciente);

    void mostrar() const;
    bool vacia() const;
};

#endif // LISTA_H
