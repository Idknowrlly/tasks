#include <iostream>
#include "triangle.h"
#include "point.h"

/**
* @breaf считывает точки с клавиатуры
* @return считанное знаначение в формате point
*/

point getPoint();

/**
* @breaf точка входа в программу
* @return 0, если программа выполнена корректно
*/
int main() {
    std::cout << "Введите координаты первой вершины (x y z): ";
    point A = getPoint();

    std::cout << "Введите координаты второй вершины (x y z): ";
    point B = getPoint();

    std::cout << "Введите координаты третьей вершины (x y z): ";
    point C = getPoint();

    triangle tri(A, B, C);

    double r_inscribed = tri.inscribedRadius();
    double r_circumscribed = tri.circumscribedRadius();

    std::cout << "\nРадиус вписанной окружности: " << r_inscribed << std::endl;
    std::cout << "Радиус описанной окружности: " << r_circumscribed << std::endl;

    return 0;
}

point getPoint()
{
    double x = 0;
    double y = 0;
    double z = 0;
    std::cin >> x >> y >> z;
    if (std::cin.fail())
    {
        std::cout << "error" << std::endl;
        exit(1);
    }
    return point(x, y, z);
}
