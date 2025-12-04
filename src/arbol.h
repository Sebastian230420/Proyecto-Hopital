#ifndef ARBOL_H
#define ARBOL_H

#include <string>
#include <iostream>

class ArbolMedicos {
private:
    struct Nodo {
        std::string nombre;
        std::string especialidad;
        Nodo* izq;
        Nodo* der;
        Nodo(const std::string& n, const std::string& e)
            : nombre(n), especialidad(e), izq(nullptr), der(nullptr) {}
    };
    Nodo* raiz;

    void insertarRec(Nodo*& nodo, const std::string& nombre, const std::string& esp);
    void inordenRec(Nodo* nodo) const;
    void destruirRec(Nodo* nodo);

public:
    ArbolMedicos();
    ~ArbolMedicos();

    // Métodos públicos
    void agregarMedico(const std::string& nombre, const std::string& esp);
    void mostrarMedicos() const;
    // Aliases para compatibilidad
    void insertar(const std::string& nombre, const std::string& esp);
    void mostrar() const;
};

#endif // ARBOL_H
