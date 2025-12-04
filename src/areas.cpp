#include "areas.h"

Areas::Areas() : lista() {}

void Areas::agregar(const std::string& a) {
    lista.push_back(a);
}

void Areas::mostrar() const {
    std::cout << "\n--- Áreas ---\n";
    for (size_t i = 0; i < lista.size(); ++i) {
        std::cout << (i+1) << ". " << lista[i] << "\n";
    }
    std::cout << "--------------\n";
}

std::string Areas::obtener(int idx) const {
    if (idx < 0 || idx >= (int)lista.size()) return std::string();
    return lista[idx];
}
