#include "CppUnitTest.h"
#include "../task_2/Teacher.h"
#include "../task_2/Position.h"
#include "../task_2/AcademicDegree.h"
#include "../task_2/AcademicRank.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TeacherTests
{
    TEST_CLASS(PositionTests)
    {
    public:
        TEST_METHOD(Position_Create_Success)
        {
            // Arrange
            std::string expected = "доцент";

            // Act
            Position p(expected);

            // Assert
            Assert::AreEqual(expected, p.toString());
        }

        TEST_METHOD(Position_Default_Empty)
        {
            // Arrange & Act
            Position p;

            // Assert
            Assert::AreEqual(std::string("не указана"), p.toString());
        }

        TEST_METHOD(Position_CompareEqual_Success)
        {
            // Arrange
            Position p1("профессор");
            Position p2("профессор");

            // Assert
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(Position_CompareNotEqual_Success)
        {
            // Arrange
            Position p1("доцент");
            Position p2("профессор");

            // Assert
            Assert::IsTrue(p1 != p2);
        }
    };

    TEST_CLASS(AcademicDegreeTests)
    {
    public:
        TEST_METHOD(Degree_Create_Success)
        {
            // Arrange
            std::string expected = "доктор наук";

            // Act
            AcademicDegree d(expected);

            // Assert
            Assert::AreEqual(expected, d.toString());
        }

        TEST_METHOD(Degree_Default_Empty)
        {
            // Arrange & Act
            AcademicDegree d;

            // Assert
            Assert::AreEqual(std::string("не указана"), d.toString());
        }
    };

    TEST_CLASS(AcademicRankTests)
    {
    public:
        TEST_METHOD(Rank_Create_Success)
        {
            // Arrange
            std::string expected = "профессор";

            // Act
            AcademicRank r(expected);

            // Assert
            Assert::AreEqual(expected, r.toString());
        }

        TEST_METHOD(Rank_Default_Empty)
        {
            // Arrange & Act
            AcademicRank r;

            // Assert
            Assert::AreEqual(std::string("не указано"), r.toString());
        }
    };

    TEST_CLASS(TeacherTests)
    {
    public:
        TEST_METHOD(Teacher_ToString_Success)
        {
            // Arrange
            Position pos("профессор");
            AcademicDegree deg("доктор наук");
            AcademicRank rank("профессор");
            Teacher t("Иванов", "Иван", "Иванович", pos, deg, rank);

            // Act
            std::string result = t.toString();

            // Assert
            std::string expected = "Иванов Иван Иванович, профессор, доктор наук, профессор";
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(Teacher_CompareByLastName_Success)
        {
            // Arrange
            Teacher t1("Петров", "Петр", "Петрович", Position("доцент"), AcademicDegree("кандидат наук"), AcademicRank("доцент"));
            Teacher t2("Иванов", "Иван", "Иванович", Position("профессор"), AcademicDegree("доктор наук"), AcademicRank("профессор"));

            // Assert
            Assert::IsTrue(t2.compareBy(t1, 0)); // Иванов < Петров
            Assert::IsFalse(t1.compareBy(t2, 0));
        }

        TEST_METHOD(Teacher_CompareByPosition_Success)
        {
            // Arrange
            Teacher t1("Иванов", "Иван", "Иванович", Position("доцент"), AcademicDegree("кандидат наук"), AcademicRank("доцент"));
            Teacher t2("Петров", "Петр", "Петрович", Position("ассистент"), AcademicDegree("нет"), AcademicRank("нет"));

            // Assert
            Assert::IsTrue(t2.compareBy(t1, 1)); // ассистент < доцент
            Assert::IsFalse(t1.compareBy(t2, 1));
        }

        TEST_METHOD(Teacher_CompareByRank_Success)
        {
            // Arrange
            Teacher t1("Иванов", "Иван", "Иванович", Position("профессор"), AcademicDegree("доктор наук"), AcademicRank("профессор"));
            Teacher t2("Петров", "Петр", "Петрович", Position("доцент"), AcademicDegree("кандидат наук"), AcademicRank("доцент"));

            // Assert
            Assert::IsTrue(t2.compareBy(t1, 2)); // доцент < профессор
        }

        TEST_METHOD(Teacher_CompareByDegree_Success)
        {
            // Arrange
            Teacher t1("Иванов", "Иван", "Иванович", Position("профессор"), AcademicDegree("доктор наук"), AcademicRank("профессор"));
            Teacher t2("Петров", "Петр", "Петрович", Position("доцент"), AcademicDegree("кандидат наук"), AcademicRank("доцент"));

            // Assert
            Assert::IsTrue(t2.compareBy(t1, 3)); // кандидат наук < доктор наук
        }
    };
}