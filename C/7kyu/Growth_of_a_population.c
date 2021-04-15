#include <math.h>

int nbYear(int p0, double percent, int aug, int p) {
    return percent > 0 ? ceil( (log(aug + p * percent / 100) - log(aug + p0 * percent / 100)) / log(1 + percent / 100) )
                       : ceil( (float) (p - p0) / aug );
}
