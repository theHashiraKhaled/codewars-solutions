#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char *decode(const unsigned char *code, size_t n, unsigned k)
{
    char *key;
    asprintf(&key, "%d", k);
    char *output = calloc(n + 1, 1);

    for (size_t i = 0, key_len = strlen(key); i < n; i++)
        output[i] = code[i] + 'a' - 1 - key[i % key_len] + '0';   

    return output;
}
