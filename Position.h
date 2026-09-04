#pragma once
#include <string>
#include <iostream>

/**
    @brief   класс Должность
*/
class Position {
private:
    std::string value;  ///< текущая должность

public:
    /**
        @brief конструктор по умолчанию
    */
    Position();

    /**
        @brief конструктор с параметром
        @param pos должность
    */
    Position(const std::string& pos);

    /**
        @brief получить текущую должность
        @return строка с должностью
    */
    std::string toString() const;

    /**
        @brief оператор ввода из потока
        @param is входной поток
        @param pos объект должности
        @return поток
    */
    friend std::istream& operator>>(std::istream& is, Position& pos);

    /**
        @brief оператор сравнения
        @param other другая должность
        @return true если равны
    */
    bool operator==(const Position& other) const;

    /**
        @brief оператор сравнения
        @param other другая должность
        @return true если не равны
    */
    bool operator!=(const Position& other) const;
};