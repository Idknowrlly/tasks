#pragma once
#include <string>
#include <iostream>
#include "Position.h"
#include "AcademicDegree.h"
#include "AcademicRank.h"

/**
    @brief   класс Преподаватель
*/
class Teacher {
private:
    std::string lastName;       ///< фамилия
    std::string firstName;      ///< имя
    std::string patronymic;     ///< отчество
    Position position;          ///< должность
    AcademicDegree degree;      ///< научная степень
    AcademicRank rank;          ///< научное звание

public:
    Teacher();
    Teacher(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
        const Position& position, const AcademicDegree& degree, const AcademicRank& rank);

    /**
        @brief статический метод чтения преподавателя из стандартного потока ввода
    */
    static Teacher readFromStream();

    /**
        @brief метод сериализации объекта в строку
    */
    std::string toString() const;

    /**
        @brief метод сравнения по выбранному критерию
        @param criterion 0 - фамилия, 1 - должность, 2 - научное звание, 3 - научная степень
    */
    bool compareBy(const Teacher& other, int criterion) const;

    std::string getLastName() const;
    Position getPosition() const;
    AcademicRank getRank() const;
    AcademicDegree getDegree() const;

    friend std::istream& operator>>(std::istream& is, Teacher& t);
};