#include <stdbool.h>

char* isSortedAndHow(int* array, int arrayLength)
{
    bool asc = true, des = true;
    int i = 1;
    while (i < arrayLength && (asc || des))
    {
        if (array[i - 1] < array[i] && des) des = false;
        if (array[i - 1] > array[i] && asc) asc = false;
        i++;
    }
    return !(asc || des) ? "no" : (asc ? "yes, ascending" : "yes, descending");
}
