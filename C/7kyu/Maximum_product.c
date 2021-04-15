#include <stddef.h>
#include <limits.h>

int adjacentElementsProduct(int inputArray[], size_t input_size) 
{
    int maximum = INT_MIN;
    for (int i = 1; i < (int) input_size; i++)
        if (inputArray[i - 1] * inputArray[i] > maximum)
            maximum = inputArray[i - 1] * inputArray[i];
    return maximum;
}
