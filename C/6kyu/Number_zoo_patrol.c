#include <stdlib.h>
#include <string.h>

void swap(int *a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++)
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quick_sort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

unsigned find_number(const unsigned *arr, size_t len)
{
    unsigned *copy = calloc(len, sizeof(unsigned));
    for (int i = 0; i < len; i++) copy[i] = arr[i];
    quick_sort(copy, 0, len - 1);
    for (int i = 0; i < len; i++) 
        if (copy[i] != i + 1)
            return i + 1;
    
    return len + 1;
}
