#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#include <stdbool.h>

/**
* @brief проверяет корректно ли выделена память под массив
* @param arr - проверяемый массив
*/
void checkPointer(const int* arr);

/**
* @brief считывает значение введённое с клавиатуры, с проверкой ввода
* @return число
*/
int getValue(void);

/**
* @brief проверяет промежуток на корректность
* @param low - нижняя граница промежутка
* @param up - верхняя граница промежутка
*/
void checkInterval(const int low, const int up);

/**
* @brief заполняет массив элементами, которые задаёт пользователь
* @param arr - массив, который будет заполнен
* @param size - размер массива
* @param low - нижняя граница промежутка, в котором будут заданы числа
* @param up - верхняя граница промежутка, в котором будут заданы числа
*/
void getManual(int* arr, const size_t size, const int low, const int up);

/**
* @brief заполняет массив случайными элементами
* @param arr - массив, который будет заполнен
* @param size - размер массива
* @param low - нижняя граница промежутка, в котором будут заданы числа
* @param up - верхняя граница промежутка, в котором будут заданы числа
*/
void getRandom(int* arr, const size_t size, const int low, const int up);

/**
* @brief проверяет, лежит ли число в заданном промежутке
* @param value - число
* @param low - нижняя граница промежутка, в котором будут заданы числа
* @param up - верхняя граница промежутка, в котором будут заданы числа
*/
void checkValueInInterval(const int value, const int low, const int up);

/**
* @brief выводит массив на экран
* @param arr - массив, который будет выведен
* @param size - размер массива
*/
void printArr(const int* arr, const size_t size);

/**
* @brief копирует массив
* @param arr - массив, который будет скопирован
* @param size - размер массива
* @return скопированный массив
*/
int* getcopy(const int* arr, const size_t size);

/**
* @brief Проверяет что переменная не меньше единицы
* @param size - значение проверяемой переменной
*/
void checkSize(const int size);

/**
* @brief замена второго элемента массива на максимальный среди отрицательных
* @param arr - массив
* @param size - размер массива
* @return изменённый массив
*/
int* comTaskOne(int* arr, const size_t size);

/**
* @brief подсчет положительных элементов массива, не превосходящих по модулю число A
* @param arr - массив
* @param size - размер массива
* @param A - заданное число
* @return - количество элементов
*/
int comTaskTwo(const int* arr, const size_t size, const int A);

/**
* @brief поиск номера первой пары соседних элементов с суммой меньше заданного числа
* @param arr - массив
* @param size - размер массива
* @param number - заданное число
* return - индекс первого элемента пары
*/
int comTaskThree(int* arr, const size_t size, const int number);

/**
* @param ChoiseManual - выбор ручного заполнения
* @param ChoiceRandom - выбор заполнения случайными числами
* @param TaskOne - выбор выполнения 1 задания
* @param TaskTwo - выбор выполнения 2 задания
* @param TaskThree - выбор выполнения 3 задания
*/
enum { ChoiseManual = 1, ChoiceRandom, TaskOne = 1, TaskTwo, TaskThree };

/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно, 1 в противоположном случае
*/
int main(void)
{
    setlocale(LC_ALL, "Russian");

    printf("Введите количество элементов массива: ");
    size_t size = (size_t)getValue();
    checkSize(size);

    int* mainArr = calloc(size, sizeof(int));
    checkPointer(mainArr);

    printf("Введите нижнюю границу массива: ");
    const int low = getValue();
    printf("Введите верхнюю границу массива: ");
    const int up = getValue();
    checkInterval(low, up);
    printf("\nМассив из %zu строк будет заполнен числами в диапазоне [%d;%d]\n\n", size, low, up);

    printf("Выберите способ заполнения массива\n%d - Ручное заполнение\n%d - Автоматическое заполнение\n", ChoiseManual, ChoiceRandom);
    int firstchoise = getValue();

    switch (firstchoise)
    {
    case ChoiseManual:
        getManual(mainArr, size, low, up);
        break;

    case ChoiceRandom:
        getRandom(mainArr, size, low, up);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(mainArr);
        exit(1);
    }

    int* copyArr = getcopy(mainArr, size);
    printArr(copyArr, size);

    printf("\nВыберите, что сделать\n%d - Заменить второй элемент массива на максимальный среди отрицательных.\n%d - Найти количество тех элементов, значения которых положительны и по модулю не превосходят заданное число А. \n%d - Найти номер первой пары соседних элементов, сумма которых меньше заданного числа.\n", TaskOne, TaskTwo, TaskThree);

    int secondchoice = getValue();

    switch (secondchoice)
    {

    case TaskOne:
        comTaskOne(copyArr, size);
        printArr(copyArr, size);
        break;

    case TaskTwo:
        printf("\nВведите число A: ");
        const int A = getValue();
        const int count = comTaskTwo(copyArr, size, A);
        printf("Количество положительных элементов, не превосходящих %d по модулю: %d\n", A, count);
        break;

    case TaskThree:
        printf("\nВведите число для сравнения с суммой пары: ");
        const int number = getValue();
        const int pairIndex = comTaskThree(copyArr, size, number);
        printf("Первая пара соседних элементов с суммой меньше %d: %d, %d\n", number, copyArr[pairIndex], copyArr[pairIndex + 1]);
        printf("Индекс первого элемента пары: %d, номер пары: %d\n", pairIndex, pairIndex+1);
        break;

    default:
        fprintf(stderr, "Error Ошибка выбора\n");
        free(mainArr);
        free(copyArr);
        exit(1);
    }

    free(mainArr);
    free(copyArr);
    return 0;
}

void checkPointer(const int* arr)
{
    if (arr == NULL)
    {
        fprintf(stderr, "Error Ошибка выделения памяти\n");
        exit(1);
    }
}

int getValue(void)
{
    int Value = 0;
    if (!scanf_s("%d", &Value))
    {
        fprintf(stderr, "Error Ошибка ввода\n");
        exit(1);
    }
    return Value;
}

void checkInterval(const int low, const int up)
{
    if (low >= up)
    {
        fprintf(stderr, "Error Ошибка ввода промежутка\n");
        exit(1);
    }
}

void getManual(int* arr, const size_t size, const int low, const int up)
{
    checkPointer(arr);

    for (size_t i = 0; i < size; i++)
    {
        printf("\narr[%zu] = ", i);
        arr[i] = getValue();
        checkValueInInterval(arr[i], low, up);
    }
}

void getRandom(int* arr, const size_t size, const int low, const int up)
{
    checkPointer(arr);
    srand(time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % (up - low + 1) + low;
    }
}

void checkValueInInterval(const int value, const int low, const int up)
{
    if (value<low || value>up)
    {
        fprintf(stderr, "Error Ошибка ввода числа, оно должно лежать в указаном промежутке\n");
        exit(1);
    }
}

void printArr(const int* arr, const size_t size)
{
    checkPointer(arr);

    printf("Массив: \n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%5d\n", arr[i]);
    }
}

int* getcopy(const int* arr, const size_t size)
{
    checkPointer(arr);
    int* copyarray = calloc(size, sizeof(int));
    checkPointer(copyarray);
   

    for (size_t i = 0; i < size; i++)
    {
        copyarray[i] = arr[i];
    }
    return copyarray;
}

void checkSize(const int size)
{
    if (size < 1)
    {
        fprintf(stderr, "Error Размер массива должен быть не меньше 1");
        exit(1);
    }
}

int* comTaskOne(int* arr, const size_t size)
{
    checkPointer(arr);

    if (size < 2)
    {
        fprintf(stderr, "Error Массив слишком мал для замены второго элемента!\n");
        exit(1);
    }

    int maxNegative = -100;
    int found = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] < 0 && (found == 0 || arr[i] > maxNegative))
        {
            maxNegative = arr[i];
            found = 1;
        }
    }

    if (found == 1)
    {
        printf("Максимальный отрицательный элемент: %d\n", maxNegative);
        arr[1] = maxNegative;
    }
    else
    {
        fprintf(stderr, "Error В массиве нет отрицательных элементов.\n");
        exit(1);
    }
}

int comTaskTwo(const int* arr, const size_t size, const int A)
{
    checkPointer(arr);

    int count = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && abs(arr[i]) <= A)
        {
            count++;
        }
    }

    return count;
}

int comTaskThree(int* arr, const size_t size, const int number)
{
    checkPointer(arr);

    if (size < 2)
    {
        fprintf(stderr, "Error размер массива слишком мал для поиска пар!\n");
        exit(1);
    }

    for (size_t i = 0; i < size - 1; i++)
    {
        if (arr[i] + arr[i + 1] < number)
        {
            return i;
        }
    }

    printf("такой пары элементов в массиве не нашлось");
    exit(1);
}