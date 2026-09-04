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
    AcademicRank();
    AcademicRank(const std::string& rank);
    std::string toString() const;
    friend std::istream& operator>>(std::istream& is, AcademicRank& rank);
    bool operator==(const AcademicRank& other) const;
    bool operator!=(const AcademicRank& other) const;
};