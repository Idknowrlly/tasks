#include <stdio.h>
#include <math.h>
#include <locale.h>

/**
* @brief Рассчитывает функцию A по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getA(const double x, const double y, const double z);

/**
* @brief Рассчитывает функцию B по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитанное значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief Точка входа в программу
* @return возвращает 0, если прогамма выполнена корректно
*/
int main(void)
{
	setlocale(LC_ALL, "Russian");
	const double x = 0.61;
	const double y = 0.9;
	const double z = 0.3;
	printf("Значение переменной А = %lf\n", getA(x, y, z));
	printf("Значение переменной B = %lf", getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z)
{
	return (pow(z, 2 * x) + pow(y, -x) * cos(x + y) * x) / (x + 1);
}

double getB(const double x, const double y, const double z)
{
	return sqrt(pow(x, 2) + y) - pow(y, 2) * pow(sin((x + z) / x), 3);
}
