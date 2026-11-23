#include <stdio.h>
#include <stdlib.h>
#include "myarrfunc.h"

static void print_menu(void)
{
    printf("\n"
           "a Задать размер массива\n"
           "b Заполнить массив\n"
           "c Представление массива (значения, адреса)\n"
           "d Поиск значения последнего отрицательного элемента\n"
           "e Сумма элементов в диапазоне значений k-m\n"
           "f Количество элементов выше среднего значения\n"
           "g Выход\n"
           "Выберите пункт: ");
}

static int read_size(size_t *n)
{
    long long v;
    if (scanf("%lld", &v) != 1 || v <= 0) {
        return 0;
    }
    *n = (size_t)v;
    return 1;
}

int main(void)
{
    size_t n = 0;
    long long *arr = NULL;
    int running = 1;

    while (running) {
        char ch;

        print_menu();
        if (scanf(" %c", &ch) != 1) {
            if (feof(stdin)) {
                break;
            }
            printf("Ошибка ввода\n");
            break;
        }

        switch (ch) {
        case 'a': {
            size_t new_n;
            printf("Введите размер массива: ");
            if (!read_size(&new_n)) {
                printf("Ошибка: размер должен быть положительным числом\n");
                break;
            }
            {
                long long *tmp = realloc(arr, new_n * sizeof(long long));
                if (tmp == NULL) {
                    printf("Ошибка выделения памяти\n");
                    break;
                }
                arr = tmp;
            }
            n = new_n;
            printf("Размер массива: %zu\n", n);
            break;
        }
        case 'b':
            if (n == 0) {
                printf("Сначала задайте размер массива\n");
                break;
            }
            printf("Введите %zu элементов:\n", n);
            {
                int ok = 1;
                for (size_t i = 0; i < n; ++i) {
                    if (scanf("%lld", &arr[i]) != 1) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok) {
                    printf("Ошибка ввода элементов\n");
                } else {
                    printf("Массив заполнен\n");
                }
            }
            break;
        case 'c':
            if (n == 0) {
                printf("Сначала задайте размер массива\n");
                break;
            }
            for (size_t i = 0; i < n; ++i) {
                printf("arr[%zu] = %lld, адрес = %p\n", i, arr[i], (void *)&arr[i]);
            }
            break;
        case 'd':
            if (n == 0) {
                printf("Сначала задайте размер массива\n");
                break;
            }
            {
                long long value;
                if (last_negative_value(arr, n, &value)) {
                    printf("Последний отрицательный элемент: %lld\n", value);
                } else {
                    printf("Отрицательных элементов нет\n");
                }
            }
            break;
        case 'e':
            if (n == 0) {
                printf("Сначала задайте размер массива\n");
                break;
            }
            {
                long long k, m, sum;
                printf("Введите k и m: ");
                if (scanf("%lld %lld", &k, &m) != 2) {
                    printf("Ошибка ввода k и m\n");
                    break;
                }
                if (sum_in_value_range(arr, n, k, m, &sum)) {
                    printf("Сумма элементов в диапазоне [%lld; %lld]: %lld\n", k, m, sum);
                } else {
                    printf("Ошибка: k должно быть <= m\n");
                }
            }
            break;
        case 'f':
            if (n == 0) {
                printf("Сначала задайте размер массива\n");
                break;
            }
            {
                size_t count;
                if (count_above_average(arr, n, &count)) {
                    printf("Количество элементов выше среднего: %zu\n", count);
                } else {
                    printf("Массив пуст\n");
                }
            }
            break;
        case 'g':
            running = 0;
            break;
        default:
            printf("Неизвестный пункт меню: %c\n", ch);
            break;
        }

        if (!running) {
            break;
        }

        /* очистка остатка строки, чтобы некорректный ввод не зацикливал меню */
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            if (c == EOF) {
                break;
            }
        }
    }

    free(arr);
    return 0;
}