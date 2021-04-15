#include <stdlib.h>

int **multiplication_table(int n) 
{
    int **table = (int **) malloc(n * sizeof(int *));
  
    for (int r = 1; r <= n; r++)
    {
        table[r - 1] = (int *) malloc(n * sizeof(int));
        for (int c = 1; c <= n; c++)
            table[r - 1][c - 1] = r * c;
    }
  
    return table;
}
