#include "energia.hpp"

Energia::Energia(int carga_inicial) {
    carga_ = (carga_inicial < 0) ? 0 : carga_inicial; // Trava inicialização negativa
}

int Energia::getCarga() const {
    return carga_; // Faltava o return
}

void Energia::consumir(int quantidade) {
    if (quantidade > 0) { // Ignora quantidades negativas (exploit)
        carga_ -= quantidade;
        if (carga_ < 0) {
            carga_ = 0; // Trava consumo no limite do zero
        }
    }
}