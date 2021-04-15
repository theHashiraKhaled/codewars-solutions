#include <stddef.h>

const char *who_is_next(long long n, size_t length, const char *const a[length]) {
    long long i = n - 1;
    while (i >= length)
        i = (i - length) / 2;
    return a[i];
}
