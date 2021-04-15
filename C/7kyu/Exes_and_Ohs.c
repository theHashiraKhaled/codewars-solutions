#include <stdbool.h>
#include <string.h>

bool xo (const char* str)
{
  int count_x = 0, count_o = 0;
  for (; *str != '\0'; str++)
  {
    if (tolower(*str) == 'o') count_o++;
    else if (tolower(*str) == 'x') count_x++;
  }
  return (count_x == count_o);
}
