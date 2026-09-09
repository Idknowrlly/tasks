#include "AcademicRank.h"

AcademicRank::AcademicRank() : value("") {}

AcademicRank::AcademicRank(const std::string& rank) : value(rank) {}

std::string AcademicRank::toString() const {
    return value.empty() ? "не указано" : value;
}

std::istream& operator>>(std::istream& is, AcademicRank& rank) {
    is >> rank.value;
    return is;
}

bool AcademicRank::operator==(const AcademicRank& other) const {
    return value == other.value;
}

bool AcademicRank::operator!=(const AcademicRank& other) const {
    return value != other.value;
}