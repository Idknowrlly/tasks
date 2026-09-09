#pragma once
#include <string>
#include <iostream>

/**
    @brief   класс Научная степень
*/
class AcademicDegree {
private:
    std::string value;  ///< текущая степень

public:

    /**
       @brief Конструктор по умолчанию
    */
    AcademicDegree();

    /**
       @brief Конструктор с параметром
       @param degree Строковое представление учёной степени
    */
    AcademicDegree(const std::string& degree);

    /**
       @brief Преобразует учёную степень в строковое представление
    */
    std::string toString() const;

    /**
       @brief Оператор ввода из потока 
       @param is Поток ввода
       @param rank Объект научного звания для заполнения
       @return Ссылка на поток ввода для цепочки операций
    */
    friend std::istream& operator>>(std::istream& is, AcademicDegree& degree);

    /**
       @brief Оператор сравнения на равенство
       @param other Другая учёная степень для сравнения
       @return true, если степени равны, иначе false
    */
    bool operator==(const AcademicDegree& other) const;

    /**
       @brief Оператор сравнения на не равенство
       @param other Другая учёная степень для сравнения
       @return true, если степени не равны, иначе false
    */
    bool operator!=(const AcademicDegree& other) const;
};
