﻿#include <stdio.h>
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
 * @brief проверят, больше ли старт функции или нет
 * @return возвращает ошибку, если старт больше чем конец, иначе ничего не возвращает
 */
void checkStartEnd(const double start, const double end);

/**
* @brief проверяет, что переменная положительна
* @param step - значение проверяемой переменной
*/
void checkStep(const double step);

/**
* @brief Точка входа в программу
* @return возвращает 0, если прогамма выполнена корректно
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	printf("Введите начальное значение интервала: ");
	const double start = getValue();
	printf("Введите конечное значение интервала: ");
	const double end = getValue();
	checkStartEnd(start, end);

	printf("Введите шаг: ");
	const double step = getValue();
	checkStep(step);

	for (double x = start; x <= end + DBL_EPSILON;x = x + step)
	{
		printf("x = %.2lf, y = %.4lf\n", x, func(x));
	}
	return 0;
}

double getValue(void)
{
	double value = 0;
	if (!scanf_s("%lf", &value))
	{
		fprintf(stderr, "Error, не корректный ввод значения переменной value\n");
		exit(1);
	}
	return value;

}

double func(const double x)
{
	return 3 * x - 14 + exp(x) - exp(-x);
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		fprintf(stderr, "Error, шаг должен быть положительным\n");
		exit(1);
	}
}

void checkStartEnd(const double start, const double end)
{
	if (start > end + DBL_EPSILON)
	{
		fprintf(stderr, "Error, начальное значение интервала больше конечного");
		exit(1);
	}
}