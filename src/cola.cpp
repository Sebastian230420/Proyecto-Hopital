#include "cola.h"

// Constructor
Cola::Cola() : front(nullptr), rear(nullptr) {}

// Destructor: libera todos los nodos y pacientes restantes
Cola::~Cola() {
    while (front) {
        Node* tmp = front;
        front = front->next;
        delete tmp->p; // liberamos paciente
        delete tmp;    // liberamos nodo
    }
    rear = nullptr;
}

// Inserta una copia del paciente en la cola
void Cola::encolar(const Paciente& paciente) {
    Paciente* np = new Paciente(paciente);
    Node* node = new Node(np);
    if (!front) {
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

// Desencola y transfiere propiedad del paciente
Paciente* Cola::desencolar() {
    if (!front) return nullptr;
    Node* node = front;
    Paciente* p = node->p; // transferimos propiedad
    front = front->next;
    if (!front) rear = nullptr;
    delete node; // eliminamos nodo, paciente se devuelve
    return p;
}

// Devuelve el siguiente paciente sin extraer
Paciente* Cola::verSiguiente() const {
    return front ? front->p : nullptr;
}

bool Cola::vacia() const {
    return front == nullptr;
}

// Muestra todos los pacientes de la cola
void Cola::mostrar() const {
    std::cout << "\n--- Cola de pacientes ---\n";
    Node* aux = front;
    while (aux) {
        std::cout << aux->p->id << " | " << aux->p->nombre << " | " << aux->p->area << "\n";
        aux = aux->next;
    }
    std::cout << "-------------------------\n";
}
