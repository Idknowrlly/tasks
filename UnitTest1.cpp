#include "CppUnitTest.h"
#include "../task_3/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTests
{
    TEST_CLASS(StackTest)
    {
    public:
        // Тест конструктора по умолчанию
        TEST_METHOD(DefaultConstructor_ShouldCreateEmptyStack)
        {
            Stack s;
            Assert::IsTrue(s.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), s.getSize());
            Assert::AreEqual(std::string("[]"), s.toString());
        }

        // Тест конструктора со списком инициализации
        TEST_METHOD(InitializerListConstructor_ShouldCreateStackWithElements)
        {
            Stack s = { 1, 2, 3, 4, 5 };
            Assert::IsFalse(s.isEmpty());
            Assert::AreEqual(static_cast<size_t>(5), s.getSize());
            Assert::AreEqual(5, s.peek());  // вершина - последний элемент
            Assert::AreEqual(std::string("[1, 2, 3, 4, 5]"), s.toString());
        }

        // Тест пустого списка инициализации
        TEST_METHOD(EmptyInitializerList_ShouldCreateEmptyStack)
        {
            Stack s = {};
            Assert::IsTrue(s.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), s.getSize());
        }

        // Тест push
        TEST_METHOD(Push_ShouldAddElementToTop)
        {
            Stack s;
            s.push(10);
            s.push(20);
            s.push(30);

            Assert::AreEqual(static_cast<size_t>(3), s.getSize());
            Assert::AreEqual(30, s.peek());  // последний добавленный - на вершине
            Assert::AreEqual(std::string("[10, 20, 30]"), s.toString());
        }

        // Тест pop
        TEST_METHOD(Pop_ShouldRemoveAndReturnTopElement)
        {
            Stack s = { 10, 20, 30 };

            int value = s.pop();
            Assert::AreEqual(30, value);  // извлекается вершина
            Assert::AreEqual(static_cast<size_t>(2), s.getSize());
            Assert::AreEqual(20, s.peek());
            Assert::AreEqual(std::string("[10, 20]"), s.toString());
        }

        // Тест нескольких pop подряд (LIFO порядок)
        TEST_METHOD(Pop_ShouldRemoveElementsInLIFOOrder)
        {
            Stack s = { 1, 2, 3, 4, 5 };

            Assert::AreEqual(5, s.pop());
            Assert::AreEqual(4, s.pop());
            Assert::AreEqual(3, s.pop());
            Assert::AreEqual(static_cast<size_t>(2), s.getSize());
            Assert::AreEqual(2, s.peek());
        }

        // Тест peek
        TEST_METHOD(Peek_ShouldReturnTopElementWithoutRemoving)
        {
            Stack s = { 5, 10, 15 };

            Assert::AreEqual(15, s.peek());
            Assert::AreEqual(static_cast<size_t>(3), s.getSize());
            Assert::AreEqual(15, s.peek()); // повторный вызов возвращает то же значение
        }

        // Тест isEmpty
        TEST_METHOD(IsEmpty_ShouldReturnTrueForEmptyStack)
        {
            Stack s;
            Assert::IsTrue(s.isEmpty());

            s.push(1);
            Assert::IsFalse(s.isEmpty());

            s.pop();
            Assert::IsTrue(s.isEmpty());
        }

        // Тест конструктора копирования
        TEST_METHOD(CopyConstructor_ShouldCreateDeepCopy)
        {
            Stack original = { 1, 2, 3 };
            Stack copy(original);

            Assert::AreEqual(original.getSize(), copy.getSize());
            Assert::AreEqual(original.peek(), copy.peek());
            Assert::AreEqual(original.toString(), copy.toString());

            // Изменяем оригинал - копия не должна измениться
            original.pop();
            Assert::AreEqual(static_cast<size_t>(2), original.getSize());
            Assert::AreEqual(static_cast<size_t>(3), copy.getSize());
            Assert::AreEqual(2, original.peek());
            Assert::AreEqual(3, copy.peek());
        }

        // Тест конструктора перемещения
        TEST_METHOD(MoveConstructor_ShouldTransferOwnership)
        {
            Stack original = { 1, 2, 3 };
            std::string originalStr = original.toString();

            Stack moved(std::move(original));

            Assert::AreEqual(originalStr, moved.toString());
            Assert::IsTrue(original.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), original.getSize());
            Assert::AreEqual(static_cast<size_t>(3), moved.getSize());
        }

        // Тест оператора присваивания копированием
        TEST_METHOD(CopyAssignment_ShouldCopyContent)
        {
            Stack original = { 10, 20, 30 };
            Stack copy;
            copy = original;

            Assert::AreEqual(original.getSize(), copy.getSize());
            Assert::AreEqual(original.peek(), copy.peek());
            Assert::AreEqual(original.toString(), copy.toString());

            // Самоприсваивание
            copy = copy;
            Assert::AreEqual(original.toString(), copy.toString());
        }

        // Тест оператора присваивания перемещением
        TEST_METHOD(MoveAssignment_ShouldTransferOwnership)
        {
            Stack original = { 1, 2, 3 };
            std::string originalStr = original.toString();
            Stack moved;

            moved = std::move(original);

            Assert::AreEqual(originalStr, moved.toString());
            Assert::IsTrue(original.isEmpty());
            Assert::AreEqual(static_cast<size_t>(3), moved.getSize());
        }

        // Тест оператора равенства
        TEST_METHOD(EqualityOperator_ShouldCompareStacks)
        {
            Stack s1 = { 1, 2, 3 };
            Stack s2 = { 1, 2, 3 };
            Stack s3 = { 1, 2, 4 };
            Stack s4 = { 1, 2, 3, 4 };

            Assert::IsTrue(s1 == s2);
            Assert::IsFalse(s1 == s3);
            Assert::IsFalse(s1 == s4);
            Assert::IsTrue(s1 != s3);
        }

        // Тест toString
        TEST_METHOD(ToString_ShouldReturnCorrectStringRepresentation)
        {
            Stack s1 = { 1, 2, 3 };
            Assert::AreEqual(std::string("[1, 2, 3]"), s1.toString());

            Stack s2 = { 42 };
            Assert::AreEqual(std::string("[42]"), s2.toString());

            Stack empty;
            Assert::AreEqual(std::string("[]"), empty.toString());
        }

        // Тест clear
        TEST_METHOD(Clear_ShouldRemoveAllElements)
        {
            Stack s = { 1, 2, 3, 4, 5 };
            s.clear();

            Assert::IsTrue(s.isEmpty());
            Assert::AreEqual(static_cast<size_t>(0), s.getSize());
            Assert::AreEqual(std::string("[]"), s.toString());
        }

        // Тест исключения при pop из пустого стека
        TEST_METHOD(Pop_FromEmptyStack_ShouldThrowException)
        {
            Stack s;

            auto func = [&s]() { s.pop(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        // Тест исключения при peek из пустого стека
        TEST_METHOD(Peek_FromEmptyStack_ShouldThrowException)
        {
            Stack s;

            auto func = [&s]() { s.peek(); };
            Assert::ExpectException<std::runtime_error>(func);
        }

        // Тест больших данных
        TEST_METHOD(LargeData_ShouldWorkCorrectly)
        {
            Stack s;
            const int N = 1000;

            for (int i = 0; i < N; i++)
            {
                s.push(i);
            }

            Assert::AreEqual(static_cast<size_t>(N), s.getSize());

            for (int i = N - 1; i >= 0; i--)
            {
                Assert::AreEqual(i, s.pop());
            }

            Assert::IsTrue(s.isEmpty());
        }

        // Тест чередования операций
        TEST_METHOD(InterleavedOperations_ShouldWorkCorrectly)
        {
            Stack s;

            s.push(1);
            s.push(2);
            Assert::AreEqual(2, s.pop());

            s.push(3);
            Assert::AreEqual(3, s.peek());
            Assert::AreEqual(3, s.pop());

            s.push(4);
            s.push(5);
            Assert::AreEqual(5, s.pop());
            Assert::AreEqual(4, s.pop());

            Assert::IsTrue(s.isEmpty());
        }
    };
}