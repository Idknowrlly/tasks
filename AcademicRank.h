#pragma once
#include <string>
#include <iostream>

/**
    @brief   класс Научное звание
*/
class AcademicRank {
private:
    std::string value;  ///< текущее звание

public:

    /**
       @brief Конструктор по умолчанию
    */ 
    AcademicRank();

    /**
       @brief Конструктор с параметром
       @param rank Строковое представление научного звания
    */
    AcademicRank(const std::string& rank);

    /**
       @brief Преобразует научное звание в строковое представление
    */
    std::string toString() const;

    /**
       @brief Оператор ввода из потока
       @param is Поток ввода
       @param rank Объект научного звания для заполнения
       @return Ссылка на поток ввода для цепочки операций
    */
    friend std::istream& operator>>(std::istream& is, AcademicRank& rank);

    /**
       @brief Оператор сравнения на равенство
       @param other Другое научное звание для сравнения
       @return true, если звания равны, иначе false
    */
    bool operator==(const AcademicRank& other) const;

    /**
       @brief Оператор сравнения на не равенство
       @param other Другое научное звание для сравнения
       @return true, если звания не равны, иначе false
    */
    bool operator!=(const AcademicRank& other) const;
};
