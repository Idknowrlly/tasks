#include "Stack.h"
#include <sstream>

Stack::Stack() : top(nullptr), count(0)
{
}

Stack::Stack(const std::initializer_list<int>& list)
    : top(nullptr), count(0)
{
    // Сохраняем порядок: первый в списке будет внизу стека
    std::vector<int> temp(list);
    for (auto it = temp.rbegin(); it != temp.rend(); ++it)
    {
        push(*it);
    }
}

Stack::Stack(const Stack& other)
    : top(nullptr), count(0)
{
    if (other.isEmpty())
    {
        return;
    }

    // Восстанавливаем порядок элементов
    std::vector<int> temp;
    Node* current = other.top;
    while (current != nullptr)
    {
        temp.push_back(current->data);
        current = current->next;
    }

    for (auto it = temp.rbegin(); it != temp.rend(); ++it)
    {
        push(*it);
    }
}

Stack::Stack(Stack&& other) noexcept
    : top(other.top), count(other.count)
{
    other.top = nullptr;
    other.count = 0;
}

Stack::~Stack()
{
    clear();
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        Stack temp(other);
        std::swap(top, temp.top);
        std::swap(count, temp.count);
    }
    return *this;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        clear();

        top = other.top;
        count = other.count;

        other.top = nullptr;
        other.count = 0;
    }
    return *this;
}

void Stack::push(int value)
{
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    count++;
}

int Stack::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty! Cannot pop.");
    }

    Node* temp = top;
    int value = temp->data;
    top = top->next;

    delete temp;
    count--;
    return value;
}

int Stack::peek() const
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty! Cannot peek.");
    }
    return top->data;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

size_t Stack::getSize() const
{
    return count;
}

void Stack::clear()
{
    while (!isEmpty())
    {
        pop();
    }
}

std::string Stack::toString() const
{
    std::ostringstream oss;
    oss << "[";

    // Собираем элементы для вывода от основания к вершине
    std::vector<int> temp;
    Node* current = top;
    while (current != nullptr)
    {
        temp.push_back(current->data);
        current = current->next;
    }

    for (auto it = temp.rbegin(); it != temp.rend(); ++it)
    {
        oss << *it;
        if (std::next(it) != temp.rend())
        {
            oss << ", ";
        }
    }

    oss << "]";
    return oss.str();
}

bool Stack::operator==(const Stack& other) const
{
    if (count != other.count)
    {
        return false;
    }

    Node* currentThis = top;
    Node* currentOther = other.top;

    while (currentThis != nullptr && currentOther != nullptr)
    {
        if (currentThis->data != currentOther->data)
        {
            return false;
        }
        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }

    return true;
}