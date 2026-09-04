#include "AcademicDegree.h"

AcademicDegree::AcademicDegree() : value("") {}

AcademicDegree::AcademicDegree(const std::string& degree) : value(degree) {}

std::string AcademicDegree::toString() const {
    return value.empty() ? "не указана" : value;
}

std::istream& operator>>(std::istream& is, AcademicDegree& degree) {
    is >> degree.value;
    return is;
}

bool AcademicDegree::operator==(const AcademicDegree& other) const {
    return value == other.value;
}

bool AcademicDegree::operator!=(const AcademicDegree& other) const {
    return value != other.value;
}