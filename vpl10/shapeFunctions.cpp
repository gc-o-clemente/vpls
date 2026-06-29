#include "shapeFunctions.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

void ShapeFunctions::printShapes(const std::vector<Shape*>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << *shape << std::endl;
    }
}

double ShapeFunctions::totalArea(const std::vector<Shape*>& shapes) {
    double sum = 0.0;
    for (const auto& shape : shapes) {
        sum += shape->area();
    }
    return sum;
}

std::vector<Shape*> ShapeFunctions::getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea) {
    std::vector<Shape*> result;
    for (const auto& shape : shapes) {
        if (shape->area() > minArea) {
            result.push_back(shape);
        }
    }
    return result;
}

void ShapeFunctions::sortShapesByArea(std::vector<Shape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area();
    });
}

std::map<std::string, int> ShapeFunctions::countShapesByName(const std::vector<Shape*>& shapes) {
    std::map<std::string, int> shapeCount;
    for (const auto& shape : shapes) {
        shapeCount[shape->name()]++;
    }
    return shapeCount;
}

std::set<double> ShapeFunctions::uniqueAreas(const std::vector<Shape*>& shapes) {
    std::set<double> areas;
    for (const auto& shape : shapes) {
        areas.insert(shape->area());
    }
    return areas;
}

void ShapeFunctions::checkTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia) {
    double area_livre = area_ambiente - totalArea(shapes);
    
    std::cout << std::fixed << std::setprecision(2);
    if (area_livre > tolerancia) {
        std::cout << "Ambiente trafegavel. Area livre: " << area_livre << std::endl;
    } else {
        std::cout << "Ambiente nao trafegavel. Area livre insuficiente: " << area_livre << std::endl;
    }
}