#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *alphabet_position(char *text) 
{
    size_t n = strlen(text);
    char *output = calloc(n, sizeof(char));
    
    for (int i = 0; i < (int) n; i++)
    {
        int pos = tolower(text[i]) - 'a' + 1;
        if (1 <= pos && pos <= 26)
        {
            char *to_add;
            asprintf(&to_add, "%d ", pos);
            strcat(output, to_add);
        }
    }
    output[strlen(output) - 1] = '\0';

    return output;
}
