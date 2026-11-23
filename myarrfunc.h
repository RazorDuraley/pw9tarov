#ifndef MYARRFUNC_H
#define MYARRFUNC_H

#include <stddef.h>

/* Функция №7: значение последнего отрицательного элемента.
   возвращает 1 при успехе, 0 если отрицательных элементов нет. */
int last_negative_value(const long long *arrptr, size_t n, long long *value);

/* Функция №16: сумма элементов в диапазоне значений [k; m].
   возвращает 1 при успехе, 0 если k > m. */
int sum_in_value_range(const long long *arrptr, size_t n,
                       long long k, long long m, long long *sum);

/* Функция №25: количество элементов выше среднего арифметического.
   возвращает 1 при успехе, 0 при n == 0. */
int count_above_average(const long long *arrptr, size_t n, size_t *count);

#endif