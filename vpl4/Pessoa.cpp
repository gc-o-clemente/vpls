#include "Pessoa.hpp"

Pessoa::Pessoa(double coordX, double coordY) {
    x = coordX;
    y = coordY;
}

double Pessoa::getX() {
    return x;
}

double Pessoa::getY() {
    return y;
}

void Pessoa::mover(double dx, double dy) {
    x = x + dx;
    y = y + dy;
}