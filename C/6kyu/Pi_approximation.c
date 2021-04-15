#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

char* iterPi(double epsilon) 
{
    double pi = 1;
    int k = 1;
  
    while (fabs(4 * pi - M_PI) > epsilon)
        pi += (pow(-1, k++) / (2 * k - 1));
    
    char *output;
    asprintf(&output, "[%d, %.10f]", k, 4 * pi);
    return output;
}
