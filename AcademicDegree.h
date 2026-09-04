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
    AcademicDegree();
    AcademicDegree(const std::string& degree);
    std::string toString() const;
    friend std::istream& operator>>(std::istream& is, AcademicDegree& degree);
    bool operator==(const AcademicDegree& other) const;
    bool operator!=(const AcademicDegree& other) const;
};