int find_even_index(const int *values, int length) 
{
    int output, found = 0;
    for (int i = 0; i < length; i++)
    {
        int sum_right = 0, sum_left = 0;
      
        // Determine sum_right
        for (int r = 0; r < i; r++)
            sum_right += values[r];
      
        // Determine sum_left
        for (int l = i + 1; l < length; l++)
            sum_left += values[l];
        
        // isEqual?
        if (sum_right == sum_left)
        {
            output = i;
            found = 1;
            break;
        }
    }
    return found ? output : -1;
}
