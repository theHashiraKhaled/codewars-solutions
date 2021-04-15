#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned char *encode(const char *s, unsigned k)
{
    char *key;
    asprintf(&key, "%d", k);
    size_t key_len = strlen(key);
    size_t str_len = strlen(s);
    unsigned char *output = malloc(str_len);
  
    for (int i = 0; i < str_len; i++)
        output[i] = s[i] - 'a' + 1 + key[i % key_len] - '0';
    free(key);
  
    return output;
}
