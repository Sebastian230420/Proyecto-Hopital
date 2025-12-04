#ifndef COLA_H
#define COLA_H

#include "paciente.h"
#include <iostream>

class Cola {
private:
    struct Node {
        Paciente* p;
        Node* next;
        Node(Paciente* _p) : p(_p), next(nullptr) {}
    };
    Node* front;
    Node* rear;

public:
    Cola();
    ~Cola();

    // Inserta una copia del paciente en la cola
    void encolar(const Paciente& paciente);

    // Desencola y devuelve el puntero al paciente (transfiere propiedad)
    // Retorna nullptr si la cola está vacía
    Paciente* desencolar();

    // Ver el siguiente paciente sin extraer (no transfiere propiedad)
    Paciente* verSiguiente() const;

    bool vacia() const;
    void mostrar() const;
};

#endif // COLA_H
