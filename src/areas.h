#ifndef AREAS_H
#define AREAS_H

#include <vector>
#include <string>
#include <iostream>

class Areas {
private:
    std::vector<std::string> lista;

public:
    Areas(); // Constructor
    void agregar(const std::string& a);
    void mostrar() const;
    std::string obtener(int idx) const;
    int size() const { return (int)lista.size(); }
};

#endif // AREAS_H
