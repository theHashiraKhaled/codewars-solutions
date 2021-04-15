#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *DuplicateEncoder(char *str)
{
    size_t len = strlen(str);
    char *output = calloc(len, sizeof(char));
  
    for (int i = 0; i < len; i++)
    {
        char current = tolower(str[i]);
        int count = 0;
        for (int j = 0; j < len; j++)
            if (tolower(str[j]) == current)
                count++;
        if (count >= 2) output[i] = ')';
        else            output[i] = '(';
    }

    return output;
}
