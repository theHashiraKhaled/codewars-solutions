#include <stdlib.h>
#include <string.h>

char* reverseWords(const char* text) {
  char *output;
  int start = 0, end = 0, i;
  
  output = malloc(strlen(text) + 1);
  for (; end < strlen(text) + 1; end++) {
    if (text[end] != ' ' && text[end] != '\0')
      continue;
    
    for (i = 0; i < end - start; i++)
        output[start + i] = text[end - 1 - i];

    output[end] = text[end];
    start = end + 1;
  }
  
  return output;
}
