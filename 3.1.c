#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

/**
* @brief считывает значение, введенное с клавиатуры с проверкой ввода
* @return считанное значение
*/
double getValue();

/**
* @brief Рассчитывает значение по заданной формуле
* @param x - значение переменной
* @return рассчитанное значение переменной
*/
double func(const double x);


/**
* @brief проверяет, что переменная положительна
* @param step - значение проверяемой переменной
*/
void checkValue(const double step);

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Введите начальное значение интервала: ");
	double start = getValue();
	printf("Введите конечное значение интервала: ");
	double end = getValue();
	printf("Введите шаг: ");
	double step = getValue();
	checkValue(step);
	for(double x = start; x < end+step+DBL_EPSILON;x=x+step)
	{ 
		printf("x = %.2lf, y = %.4lf\n", x, func(x));
	}
	return 0;
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

double func(const double x)
{
	return 3 * x - 14 + exp(x) - exp(-x);
}

void checkValue(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Value have to be positive\n");
		abort();
	}
}