#include <stddef.h>

int score_hand(size_t n, const char cards[n]) 
{
    int table[12596] = {['1'] = 1,  ['2'] = 2,  ['3'] = 3,  ['4'] = 4, ['5'] = 5,
                        ['6'] = 6,  ['7'] = 7,  ['8'] = 8,  ['9'] = 9, ['T'] = 10,
                        ['J'] = 10, ['Q'] = 10, ['K'] = 10, ['A'] = 1};
    int total = 0, contains_ace = 0;
  
    // Add up card values, treat each A as 1
    // Determine if hand contains an A
    for (int i = 0; i < n; i++)
    {
        total += table[cards[i]];
        if (cards[i] == 'A')
            contains_ace = 1;
    }
    // if hand contains Ace and total is low enough, treat A as 11
    if (contains_ace && total <= 11) total += 10;
    
    return total;
      
}
