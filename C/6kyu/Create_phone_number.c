#include <stdio.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
    sprintf(phnum, "(%d%d%d) %d%d%d-%d%d%d%d", nums[0], nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9]);
    return phnum;
}
