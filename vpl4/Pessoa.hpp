#ifndef PESSOA_HPP
#define PESSOA_HPP

struct Pessoa {
    double x;
    double y;

    Pessoa(double coordX, double coordY);
    double getX();
    double getY();
    
    void mover(double dx, double dy);
};

#endif