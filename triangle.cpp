#include "triangle.h"
#include <cmath>
#include <limits>

static bool isZero(double value) {
    return std::abs(value) < std::numeric_limits<double>::epsilon() * 1000;
}

void triangle::validateTriangle(const point& A, const point& B, const point& C) const {
    double crossLengthSquared = crossX * crossX + crossY * crossY + crossZ * crossZ;
    double area = std::sqrt(crossLengthSquared) / 2.0;
    if (isZero(area)) {
        std::cout << "Такого треугольника не существует" << std::endl;
        exit(1);
    }
}

triangle::triangle(const point& A, const point& B, const point& C)
    : A(A), B(B), C(C) {
    validateTriangle(A, B, C);
}

double triangle::sideLength(const point& P, const point& Q) const {
    double dx = P.x() - Q.x();
    double dy = P.y() - Q.y();
    double dz = P.z() - Q.z();
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double triangle::inscribedRadius() const {
    double a = sideLength(B, C);
    double b = sideLength(A, C);
    double c = sideLength(A, B);

    double p = (a + b + c) / 2.0;
    double area = std::sqrt(p * (p - a) * (p - b) * (p - c));

    return area / p;
}

double triangle::circumscribedRadius() const {
    double a = sideLength(B, C);
    double b = sideLength(A, C);
    double c = sideLength(A, B);

    double p = (a + b + c) / 2.0;
    double area = std::sqrt(p * (p - a) * (p - b) * (p - c));

    return (a * b * c) / (4.0 * area);
}
