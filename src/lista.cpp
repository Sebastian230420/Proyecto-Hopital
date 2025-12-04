#include "lista.h"

// Constructor
Lista::Lista() : head(nullptr) {}

// Destructor: libera todos los nodos y pacientes
Lista::~Lista() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp->p;
        delete tmp;
    }
}

// Inserta un paciente en la lista (toma propiedad del puntero)
void Lista::insertar(Paciente* paciente) {
    if (!paciente) return;
    Node* node = new Node(paciente);
    node->next = head;
    head = node;
}

// Inserta una copia del paciente
void Lista::insertarCopia(const Paciente& paciente) {
    Paciente* np = new Paciente(paciente);
    insertar(np);
}

// Muestra todos los pacientes de la lista
void Lista::mostrar() const {
    std::cout << "\n--- Historial de pacientes atendidos ---\n";
    Node* aux = head;
    while (aux) {
        std::cout << aux->p->id << " | " << aux->p->nombre << " | " << aux->p->area << "\n";
        aux = aux->next;
    }
    std::cout << "----------------------------------------\n";
}

bool Lista::vacia() const {
    return head == nullptr;
}
