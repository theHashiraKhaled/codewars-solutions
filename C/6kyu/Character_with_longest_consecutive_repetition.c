#include <stddef.h>

char longest_repetition(const char *chars, size_t *n) 
{
    char c = '\0';
    int max = 0;
    
    while (*chars != '\0')
    {
        char current = *chars;
        int count = 0;
        while (*chars == current)
        {
            count++;
            *chars++;
        }
        if (count > max)
        {
            c = current;
            max = count;
        }
    }
    
    return *n = max, c;
}
