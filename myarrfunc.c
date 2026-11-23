#include "myarrfunc.h"

int last_negative_value(const long long *arrptr, size_t n, long long *value)
{
    const long long *p;

    for (p = arrptr + n; p > arrptr; --p) {
        if (*(p - 1) < 0) {
            *value = *(p - 1);
            return 1;
        }
    }
    return 0;
}

int sum_in_value_range(const long long *arrptr, size_t n,
                       long long k, long long m, long long *sum)
{
    const long long *p;
    const long long *end = arrptr + n;

    if (k > m) {
        return 0;
    }

    *sum = 0;
    for (p = arrptr; p < end; ++p) {
        if (*p >= k && *p <= m) {
            *sum += *p;
        }
    }
    return 1;
}

int count_above_average(const long long *arrptr, size_t n, size_t *count)
{
    const long long *p;
    const long long *end = arrptr + n;
    long long total = 0;
    double avg;

    if (n == 0) {
        return 0;
    }

    for (p = arrptr; p < end; ++p) {
        total += *p;
    }
    avg = (double)total / (double)n;

    *count = 0;
    for (p = arrptr; p < end; ++p) {
        if ((double)*p > avg) {
            ++(*count);
        }
    }
    return 1;
}