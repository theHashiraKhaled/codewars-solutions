#include <stdlib.h>

int find_outlier(const int *values, size_t count)
{
    // Determine parity
    int odd = 0, even = 0;
    for (int i = 0; i < 3; i++)
    {
        if (values[i] % 2 == 0) even++;
        else odd++;
    }

    // Determine outlier
    if (even > odd) // Search the only odd number
    {
        int i = 0;
        while (1)
            if (values[i++] % 2 != 0)
                return values[i - 1];
    } else // Search the only even number
    {
        int i = 0;
        while (1)
            if (values[i++] % 2 == 0)
                return values[i - 1];
    }
}
