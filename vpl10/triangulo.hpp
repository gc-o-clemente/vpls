#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double s1, double s2, double s3);
    std::string name() const override;
    double area() const override;
};

#endif