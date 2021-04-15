#include <stdlib.h>
#include <string.h>

/* Note:
    should also save the length of the parts_sums in <len>
*/

unsigned long long *parts_sums(size_t *len, const unsigned long long *ls, size_t n)
{
    *len = 0;
    unsigned long long *output;
    output = (unsigned long long *)calloc(n + 1, sizeof(unsigned long long));
    memset(output, 0, sizeof output);
    long long asc = 0, des = 0;
  
    for (int i = 0; i < n; i++)
        des += ls[i];
    
    for (int i = 0; i < n; i++)
    {
        output[i] = des - asc;
        asc += ls[i];
        (*len)++;
    }
    (*len)++;

    return output;
}
