#include <string.h>

#define VOWELS "aeiou"
size_t get_count(const char *s)
{
    int count = 0;
    for (; *s != '\0'; s++)
        if (strchr(VOWELS, *s) != NULL) count++;
    return count;
}
