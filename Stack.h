#pragma once
#include <string>
#include <initializer_list>

/**
 * @brief класс Стек
 * @brief Коллекция, реализующая вставку и удаление элемента по принципу LIFO
 */
class Stack
{
private:
    struct Node
    {
        int data;      // данные, хранящиеся в узле
        Node* next;    // указатель на следующий узел

        /**
         * @brief конструктор узла
         * @param value значение для хранения в узле
         */
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;       // @brief вершина стека
    size_t count;    // @brief количество элементов

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Stack();

    /**
     * @brief конструктор со списком инициализации
     * @param list - список инициализации
     */
    Stack(const std::initializer_list<int>& list);

    /**
     * @brief конструктор копирования
     * @param other - ссылка на копируемый стек
     */
    Stack(const Stack& other);

    /**
     * @brief конструктор перемещения
     * @param other - ссылка на перемещаемый стек
     */
    Stack(Stack&& other) noexcept;

    /**
     * @brief деструктор
     */
    ~Stack();

    /**
     * @brief присваивание копированием
     * @param other - ссылка на копируемый стек
     */
    Stack& operator=(const Stack& other);

    /**
     * @brief присваивание перемещением
     * @param other - ссылка на перемещаемый стек
     */
    Stack& operator=(Stack&& other) noexcept;

    /**
     * @brief добавить элемент на вершину стека
     * @param value - значение для добавления
     */
    void push(int value);

    /**
     * @brief извлечь элемент с вершины стека
     * @return значение извлечённого элемента
     */
    int pop();

    /**
     * @brief посмотреть элемент на вершине стека
     * @return значение верхнего элемента
     */
    int peek() const;

    /**
     * @brief проверка на пустоту
     * @return true если стек пуст
     */
    bool isEmpty() const;

    /**
     * @brief получить размер стека
     * @return количество элементов
     */
    size_t getSize() const;

    /**
     * @brief очистить стек
     */
    void clear();

    /**
     * @brief вывод в строку
     * @return строковое представление стека
     */
    std::string toString() const;

    /**
     * @brief Оператор сравнения
     * @param other - другой стек
     * @return true если стеки равны
     */
    bool operator==(const Stack& other) const;
};