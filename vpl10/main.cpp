#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "shapeFunctions.hpp"

int main() {
    std::vector<Shape*> shapes;
    std::string command;

    while (std::cin >> command) {
        if (command == "CIRCLE") {
            double r;
            std::cin >> r;
            shapes.push_back(new Circle(r));
        } 
        else if (command == "RECT") {
            double w, h;
            std::cin >> w >> h;
            shapes.push_back(new Rectangle(w, h));
        } 
        else if (command == "TRIANGLE") {
            double a, b, c;
            std::cin >> a >> b >> c;
            shapes.push_back(new Triangle(a, b, c));
        } 
        else if (command == "LIST") {
            ShapeFunctions::printShapes(shapes);
        } 
        else if (command == "TOTAL") {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Total: " << ShapeFunctions::totalArea(shapes) << std::endl;
        } 
        else if (command == "SORT") {
            ShapeFunctions::sortShapesByArea(shapes);
            ShapeFunctions::printShapes(shapes);
        } 
        else if (command == "FILTER") {
            double min_area;
            std::cin >> min_area;
            std::vector<Shape*> filtered = ShapeFunctions::getShapesWithAreaGreaterThan(shapes, min_area);
            ShapeFunctions::printShapes(filtered);
        } 
        else if (command == "COUNT") {
            auto counts = ShapeFunctions::countShapesByName(shapes);
            for (const auto& pair : counts) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        } 
        else if (command == "UNIQUE") {
            auto unique_areas = ShapeFunctions::uniqueAreas(shapes);
            std::cout << std::fixed << std::setprecision(2);
            for (double area : unique_areas) {
                std::cout << area << " ";
            }
            std::cout << std::endl;
        } 
        else if (command == "CLEAR") {
            for (Shape* shape : shapes) {
                delete shape;
            }
            shapes.clear();
        } 
        else if (command == "TRAVERSABLE") {
            double env_area, tol;
            std::cin >> env_area >> tol;
            ShapeFunctions::checkTraversable(shapes, env_area, tol);
        }
    }

    // Liberação final de memória para evitar vazamentos ao fim da execução
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    return 0;
}