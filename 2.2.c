#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <float.h>


/**
 * @brief считывает значение, введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief рассчитывает значение функции Y
 * @param a - константа
 * @param x - переменная, которую вводит пользователь
 * @return возвращает рассчитанное значение функции Y
 */
double funcY(const double x, const double a);

/**
 * @brief проверяет,что переменная не равняется значению константы a
 * @param value - значение проверяемой переменной
 * @param a - константа
 */
void checkValue(const double x, const double a);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
	setlocale(LC_ALL, "Russian");
    const double a = 1.6;
    printf("Введите значение x: ");
    double x = getValue();
    checkValue(x,a);
    printf("Значение функции y = %lf", funcY(x,a));
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

double funcY(const double x, const double a)
{
    if ((x - a) > DBL_EPSILON)
    {
        return exp(a * x) - 2.5;
    }
    else
    {
        if ((a-x) > DBL_EPSILON & fabs(x) > DBL_EPSILON)
        {
            return (a / x) + sin(x);
        }
        else
        {
            return 3;
        }
    }
}

void checkValue(const double x, const double a)
{
    if (fabs(x-a)<DBL_EPSILON)
    {
        printf("Значение вводимой переменной не может равняться значению константы a");
        abort();
    }
}