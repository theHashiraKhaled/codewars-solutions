/* Return 1 if addr is a valid IP address, return 0 otherwise */

#include <stdlib.h>
#include <string.h>

#define DELIM "."

int is_valid_ip(const char * addr) 
{
    char* ip = strdup(addr);
    char* part = strtok(ip, DELIM);
    int valid_parts = 0;
  
    while (part != NULL)
    {
        int n = strlen(part);
        if (n > 3) return 0;
        for (int i = 0; i < n; i++)
            if (!(part[i] >= '0' && part[i] <= '9')) return 0;
        if (part[0] == '0' && n > 1) return 0;
        int p = atoi(part);
        if (!(p >= 0 && p <= 255)) return 0;
        else valid_parts++;
        part = strtok(NULL, DELIM);
    }

    return valid_parts == 4 ? 1 : 0;
};
