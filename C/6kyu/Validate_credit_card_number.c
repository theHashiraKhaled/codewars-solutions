#include <stdbool.h>

bool validate(long digits) 
{
    // Determine nb of digits
    int nb_digits = 0;
    long n = digits;
    while (n != 0)
    {
        n /= 10;
        nb_digits++;
    }
  
    // Initialize digits array
    int digits_array[nb_digits];
    n = digits;
    while (n != 0)
    {
        digits_array[--nb_digits] = n % 10;
        n /= 10;
    }
    
    // Luhn Algorithm
    int len = sizeof(digits_array)/sizeof(digits_array[0]);
    int sum = digits_array[len - 1];
    int parity = len % 2;
    for (int i = 0; i <= len - 2; i++)
    {
        int d = digits_array[i];
        if (i % 2 == parity) d *= 2;
        if (d > 9) d -= 9;
        sum += d;
    }
  
    return (sum % 10) == 0;
}
