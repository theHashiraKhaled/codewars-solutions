#define _GNU_SOURCE
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char* likes(size_t n, const char *const names[n]) 
{
    char *output;
    switch (n)
    {
        case 0:
            asprintf(&output, "no one likes this", names[0]);
            break;
        case 1:
            asprintf(&output, "%s likes this", names[0]);
            break;
        case 2:
            asprintf(&output, "%s and %s like this", names[0], names[1]);
            break;
        case 3:
            asprintf(&output, "%s, %s and %s like this", names[0], names[1], names[2]);
            break;
        default:
            asprintf(&output, "%s, %s and %d others like this", names[0], names[1],  (int) (n - 2));
            break;
    }
    return output;
}
