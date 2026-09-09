#include "Teacher.h"

Teacher::Teacher() : lastName(""), firstName(""), patronymic(""), position(), degree(), rank() {}

Teacher::Teacher(const std::string& lastName, const std::string& firstName, const std::string& patronymic,
    const Position& position, const AcademicDegree& degree, const AcademicRank& rank)
    : lastName(lastName), firstName(firstName), patronymic(patronymic), position(position), degree(degree), rank(rank) {
}

Teacher Teacher::readFromStream() {
    Teacher t;
    std::cin >> t;
    return t;
}

std::string Teacher::toString() const {
    return lastName + " " + firstName + " " + patronymic + ", " +
        position.toString() + ", " + degree.toString() + ", " + rank.toString();
}

bool Teacher::compareBy(const Teacher& other, int criterion) const {
    switch (criterion) {
    case 0: return lastName < other.lastName;
    case 1: return position.toString() < other.position.toString();
    case 2: return rank.toString() < other.rank.toString();
    case 3: return degree.toString() < other.degree.toString();
    default: return false;
    }
}

std::string Teacher::getLastName() const { return lastName; }
Position Teacher::getPosition() const { return position; }
AcademicRank Teacher::getRank() const { return rank; }
AcademicDegree Teacher::getDegree() const { return degree; }

std::istream& operator>>(std::istream& is, Teacher& t) {
    std::cout << "Введите фамилию, имя, отчество: ";
    is >> t.lastName >> t.firstName >> t.patronymic;
    std::cout << "Введите должность: ";
    is >> t.position;
    std::cout << "Введите научную степень: ";
    is >> t.degree;
    std::cout << "Введите научное звание: ";
    is >> t.rank;
    return is;
}