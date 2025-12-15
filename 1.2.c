#define _USE_MATH_DEFINES
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief рассчитывает площадь круга
 * @param x - длина окружности
 * @return возвращает рассчитанную площадь
 */
double getSquare(const double x);

/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
* @brief проверяет, что переменная положительна
* @param value - значение проверяемой переменной
*/
void checkValue(const double value);

/**
* @brief Точка входа в программу
* @return возвращает 0, если прогамма выполнена корректно
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите длину окружности:");
	double x = getValue();
	checkValue(x);
	printf("Площадь круга = %.2lf", getSquare(x));
	return 0;
}

double getSquare(const double x)
{
	return (x * x) / (4 * M_PI);
}

double getValue()
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		printf("Error\n");
		abort();
	}
	return value;

}

void checkValue(const double value)
{
	if (value <= DBL_EPSILON)
	{
		printf("Value have to be positive");
		abort();
	}
}