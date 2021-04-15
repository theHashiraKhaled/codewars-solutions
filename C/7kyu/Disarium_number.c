const char *disariumNumber(int number)
{
    // Determine nb of digits
    int nb_digits = 0;
    int n = number;
    while (n != 0)
    {
        n /= 10;
        nb_digits++;
    }
    
    // Initialize array
    int digits[nb_digits];
    nb_digits = 0;
    n = number;
    while (n != 0)
    {
        digits[nb_digits] = n % 10;
        n /= 10;
        nb_digits++;
    }
  
    // Determine sum
    int sum = 0, pos = 1;
    for (int i = nb_digits - 1; i >= 0; i--)
        sum += pow(digits[i], pos++);

    return sum == number ? "Disarium !!" : "Not !!";
}
