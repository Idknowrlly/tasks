#include <iostream>
#include "Stack.h"

/**
 * @brief Точка входа
 * @return 0, если код завершился успешно
 */
int main()
{
    Stack s1;
    std::cout << "1. Пустой стек s1: " << s1.toString() << std::endl;
    std::cout << "   Пустой? " << (s1.isEmpty() ? "Да" : "Нет") << std::endl;
    std::cout << "   Размер: " << s1.getSize() << std::endl << std::endl;

    Stack s2 = { 10, 20, 30, 40, 50 };
    std::cout << "2. Стек s2 (список инициализации): " << s2.toString() << std::endl;
    std::cout << "   Размер: " << s2.getSize() << std::endl << std::endl;

    s1.push(100);
    s1.push(200);
    s1.push(300);
    std::cout << "3. После добавления 100, 200, 300: " << s1.toString() << std::endl;
    std::cout << "   Размер: " << s1.getSize() << std::endl << std::endl;

    int value = s1.pop();
    std::cout << "4. Извлечено: " << value << std::endl;
    std::cout << "   После извлечения: " << s1.toString() << std::endl;

    value = s1.pop();
    std::cout << "   Извлечено: " << value << std::endl;
    std::cout << "   После извлечения: " << s1.toString() << std::endl;
    std::cout << "   Размер: " << s1.getSize() << std::endl << std::endl;

    Stack s3;
    for (int i = 1; i <= 10; i++)
    {
        s3.push(i);
    }
    std::cout << "5. Стек после добавления 1..10: " << s3.toString() << std::endl;

    std::cout << "   Извлекаем первые 5 элементов: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << s3.pop() << " ";
    }
    std::cout << std::endl;
    std::cout << "   Стек после извлечения: " << s3.toString() << std::endl;
    std::cout << "   Размер: " << s3.getSize() << std::endl << std::endl;

    // Проверка peek
    Stack s4 = { 1, 2, 3 };
    std::cout << "6. Стек s4: " << s4.toString() << std::endl;
    std::cout << "   peek(): " << s4.peek() << std::endl;
    std::cout << "   После peek() стек не изменился: " << s4.toString() << std::endl;

    return 0;
}