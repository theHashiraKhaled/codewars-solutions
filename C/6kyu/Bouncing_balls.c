#include <math.h>

int bouncingBall(double h, double b, double w) 
{
    if (h <= 0 || b <= 0 || b >= 1 || w >= h)
        return -1;
    return 2 * ceil( (log(w) - log(h)) / log(b) ) - 1;
}
