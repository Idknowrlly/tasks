#include "Position.h"

Position::Position() : value("") {}

Position::Position(const std::string& pos) : value(pos) {}

std::string Position::toString() const {
    return value.empty() ? "не указана" : value;
}

std::istream& operator>>(std::istream& is, Position& pos) {
    is >> pos.value;
    return is;
}

bool Position::operator==(const Position& other) const {
    return value == other.value;
}

bool Position::operator!=(const Position& other) const {
    return value != other.value;
}