#include <stdbool.h>
#include <math.h>

bool is_square(int n)
{
    if (n < 0 || sqrt(n) != (int) sqrt(n)) return false;
    return true;
}
