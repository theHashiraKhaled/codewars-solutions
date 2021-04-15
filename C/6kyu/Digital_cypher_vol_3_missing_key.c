#include <stddef.h>
#include <stdlib.h>
#include <string.h>

unsigned find_the_key(const char *msg, const unsigned char *code, size_t n)
{
    // Fing total key sequence
    unsigned char *seq = malloc(n);
    for (int i = 0; i < n; i++)
        seq[i] = code[i] - (msg[i] - 'a' + 1);
  
    int repeat = n - 1;
    for (int i = n - 1; i > 0; --i)
    {
        char flag = 1;
        for (int j = i; j < n; ++j)
            if (seq[j] != seq[j % i]) flag = 0;
        if (flag) repeat = i - 1;
    }
    unsigned output = 0;
    int factor = 0;
    while (repeat > -1) output += (seq[repeat--] * pow(10, factor++));
  
    return output;
}

