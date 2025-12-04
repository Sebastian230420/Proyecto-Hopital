#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <iostream>

class Matriz {
private:
    std::vector<std::vector<int>> datos;
    int filas, cols;

public:
    Matriz(int f = 3, int c = 3); // Constructor: inicializa matriz y ocupación aleatoria
    void set(int r, int c, int val); // Cambia valor (0=libre, 1=ocupado)
    int get(int r, int c) const;     // Devuelve valor o -1 si fuera de rango
    void mostrar() const;            // Muestra la matriz
    int filasCount() const { return filas; }
    int colsCount() const { return cols; }
};

#endif // MATRIZ_H
