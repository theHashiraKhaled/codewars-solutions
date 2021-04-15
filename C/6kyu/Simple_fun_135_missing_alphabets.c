#include <stdlib.h>

char *missing_alphabets(const char *s) 
{
  int table[26] = {0}, max = 0;
  char *output;
  
  while( *s )
  {
      table[ *s - 'a' ]++;
      max = ( max > table[ *s - 'a' ] ) ? max : table[ *s - 'a' ];
      s++;
  }
  
  output = calloc( max * 26, sizeof( char ));
  int k = 0;
  
  for (int i = 0; i < 26; i++)
    if (table[i] < max)
      for (int j = table[i]; j < max; j++)
        output[k++] = i + 'a';

  
  return output;
}
