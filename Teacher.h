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

    /**
        @brief   фамилия
    */
    std::string lastName;

    /**
        @brief   имя
    */
    std::string firstName;

    /**
        @brief   отчество
    */
    std::string patronymic;

    /**
        @brief   должность
    */
    Position position;

    /**
        @brief   научная степень
    */
    AcademicDegree degree;

    /**
        @brief   научное звание
    */
    AcademicRank rank;

public:

    /**
       @brief Конструктор по умолчанию
    */ 
    Teacher();

    /**
       @brief Конструктор с параметрами
       @param lastName Фамилия преподавателя
       @param firstName Имя преподавателя
       @param patronymic Отчество преподавателя
       @param position Должность преподавателя
       @param degree Учёная степень преподавателя
       @param rank Научное звание преподавателя
    */
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
    bool compareBy(const Teacher& other, const int criterion) const;

    /**
       @brief Получение фамилии преподавателя
       @return Фамилия преподавателя
    */
    std::string getLastName() const;

    /**
       @brief Получение должности преподавателя
       @return Объект Position с должностью преподавателя
    */
    Position getPosition() const;

    /**
       @brief Получение научного звания преподавателя
       @return Объект AcademicRank с научным званием преподавателя
    */
    AcademicRank getRank() const;

    /**
       @brief Получение учёной степени преподавателя
       @return Объект AcademicDeree с учёной степенью преподавателя
    */
    AcademicDegree getDegree() const;

     /**
       @brief Оператор ввода из потока
       @param is Поток ввода
       @param t Объект Teacher для заполнения
       @return Ссылка на поток ввода для цепочки операций
     */
    friend std::istream& operator>>(std::istream& is, Teacher& t);
};
