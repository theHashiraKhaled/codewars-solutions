unsigned fruit(const char **reels[], const unsigned spins[])
{
    // Gets items
    char *items[3];
    for (int i = 0; i < 3; i++)
        items[i] = reels[i][spins[i]];
    
    // Determine their how much of the same type there are
    int max_count = 0, max_index;
    int is_wild = 1;
    for (int i = 0; i < 3; i++)
    {
        char *item = items[i];
        int current_count = 0;
        for (int j = 0; j < 3; j++)
            if (items[j] == item) current_count++;
      
        if (current_count > max_count)
        {
            max_count = current_count;
            max_index = i;
        }
      
        if (item == "Wild" ) is_wild = 2;
    }
    
    // Determine coeff
    int coeff;
    switch (max_count)
    {
        case 1:
            return 0;
            break;
        case 2:
            coeff = 1;
            break;
        case 3:
            coeff = 10;
            break;
    }
  
    // Determine score
    if (items[max_index] == "Wild")
        return 10 * coeff;
        
    if (items[max_index] == "Star")
        return 9 * coeff * is_wild;
        
    if (items[max_index] == "Bell")
        return 8 * coeff * is_wild;
        
    if (items[max_index] == "Shell")
        return 7 * coeff * is_wild;
        
    if (items[max_index] == "Seven")
        return 6 * coeff * is_wild;
        
    if (items[max_index] == "Cherry")
        return 5 * coeff * is_wild;
        
    if (items[max_index] == "Bar")
        return 4 * coeff * is_wild;
        
    if (items[max_index] == "King")
        return 3 * coeff * is_wild;
        
    if (items[max_index] == "Quinn")
        return 2 * coeff * is_wild;
        
    if (items[max_index] == "Jack")
        return coeff * is_wild;

}
