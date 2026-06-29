#include <iostream>
#include "Carro.hpp"
#include <cmath>

Carro::Carro(double coordX, double coordY, double angulo_th) {
    x = coordX;
    y = coordY;
    th = angulo_th;
}

double Carro::getX() { return x; }
double Carro::getY() { return y; }
double Carro::getTH() { return th; }

void Carro::girar(double w, double t) {
    th = th + (w * t); 
}

void Carro::mover(double v, double t) {
    double distancia = v * t;
    x = x + (distancia * cos(th));
    y = y + (distancia * sin(th));
}

double Carro::calcular_distancia_pessoa(Pessoa* pessoa) {
    double dx = pessoa->x - x; 
    double dy = pessoa->y - y;
    return std::sqrt((dx * dx) + (dy * dy)); 
}

double Carro::calcular_angulo_pessoa(Pessoa* pessoa) {
    double dx = pessoa->x - x;
    double dy = pessoa->y - y;
    
    double angulo_global = std::atan2(dy, dx);
    double angulo_relativo = angulo_global - th;

    const double PI = 3.141592653589793;
    while (angulo_relativo > PI) angulo_relativo -= 2 * PI;
    while (angulo_relativo < -PI) angulo_relativo += 2 * PI;

    return angulo_relativo * (180.0 / PI); 
}

bool Carro::movimentacao_permitida(Pessoa** pessoas, int n) {
    bool pode_mover = true;
    for (int i = 0; i < n; i++) {
        double dist = calcular_distancia_pessoa(pessoas[i]);
        double angulo = calcular_angulo_pessoa(pessoas[i]);

        if (angulo >= -45.0 && angulo <= 45.0 && dist < 5.0) {
            std::cout << "Alerta!\t" << i << "\t" << angulo << "\t" << dist << "\n";
            pode_mover = false; 
        }
    }
    return pode_mover;
}

void Carro::navegar(Pessoa** pessoas, int n, double w, double v, double t) {
    if (movimentacao_permitida(pessoas, n) == true) {
        girar(w, t);
        mover(v, t);
    }
}