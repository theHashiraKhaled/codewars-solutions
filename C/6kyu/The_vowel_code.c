#include <stdlib.h>
#include <string.h>

char *encode(const char *string) 
{
  char *ret = strdup(string);
  for (char *p = ret; *p; p++)
  {
    switch (*p) 
    {
      case 'a': *p = '1'; break;
      case 'e': *p = '2'; break;
      case 'i': *p = '3'; break;
      case 'o': *p = '4'; break;
      case 'u': *p = '5'; break;
    }
  }
  return ret;
}

char *decode(const char *string)
{
  char *ret = strdup(string);
  for (char *p = ret; *p; p++)
  {
    switch (*p) 
    {
      case '1': *p = 'a'; break;
      case '2': *p = 'e'; break;
      case '3': *p = 'i'; break;
      case '4': *p = 'o'; break;
      case '5': *p = 'u'; break;
    }
  }
  return ret;
}
