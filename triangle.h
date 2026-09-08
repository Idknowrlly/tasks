#pragma once
#include "point.h"
#include <cmath>

/**
    @brief   класс Треугольник
    @brief   Задан тремя точками. Позволяет вычислить радиусы вписанной и описанной окружностей.
*/
class triangle {
private:
    point A, B, C;  ///< вершины треугольника

    /**
        @brief   вычисление длины стороны между двумя точками
        @param   P первая точка
        @param   Q вторая точка
        @return  евклидово расстояние
    */
    double sideLength(const point& P, const point& Q) const;

    /**
        @brief   проверяет, что точки образуют треугольник
        @param   A первая вершина
        @param   B вторая вершина
        @param   C третья вершина
        @throw   std::invalid_argument если треугольник вырожден
    */
    void validateTriangle(const point& A, const point& B, const point& C) const;

public:
    /**
        @brief   конструктор треугольника
        @param   A первая вершина
        @param   B вторая вершина
        @param   C третья вершина
        @throw   std::invalid_argument если точки не образуют треугольник
    */
    triangle(const point& A, const point& B, const point& C);

    /**
        @brief   вычисление радиуса вписанной окружности
        @return  радиус вписанной окружности
    */
    double inscribedRadius() const;

    /**
        @brief   вычисление радиуса описанной окружности
        @return  радиус описанной окружности
    */
    double circumscribedRadius() const;
};
