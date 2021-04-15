#include <stdlib.h>

size_t *mine_location(size_t n, int field[n][n]) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (field[i][j] == 1)
            {
                size_t *output = calloc(2, sizeof(size_t));
                output[0] = i;
                output[1] = j;
                return output;
            }
    
}
