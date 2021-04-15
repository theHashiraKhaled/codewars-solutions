int queue_time(const int *customers, int customers_length, int n)
{
    if (!customers) return 0;
  
    int tills[n];
    for (int i = 0; i < n; i++)
        tills[i] = 0;
    
    for (int i = 0; i < customers_length; i++)
    {
        tills[0] += customers[i];
        for (int c = 0; c < n - 1; c++)
            for (int d = 0; d < n - c - 1; d++)
                if (tills[d] > tills[d + 1])
                {
                    int swap = tills[d];
                    tills[d] = tills[d + 1];
                    tills[d + 1] = swap;
                }
    }
    
  int maximum = tills[0];;
  for (int c = 1; c < n; c++)
    if (tills[c] > maximum)
        maximum = tills[c];
  return maximum;
}
