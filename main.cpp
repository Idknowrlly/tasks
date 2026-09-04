#include <iostream>
#include <vector>
#include "Teacher.h"

int main() {
    std::vector<Teacher> teachers;
    int count;

    std::cout << "Введите количество преподавателей: ";
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::cout << "\n--- Преподаватель " << i + 1 << " ---" << std::endl;
        teachers.push_back(Teacher::readFromStream());
    }

    std::cout << "\n--- Список преподавателей ---" << std::endl;
    for (const auto& t : teachers) {
        std::cout << t.toString() << std::endl;
    }

    return 0;
}