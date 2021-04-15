#include <stddef.h>

char *maze_runner(const int *maze, size_t n, const char *directions) 
{
    // Find start position
    int position;
    for (int r = 0; r < (int) n; r++)
        for (int c = 0; c < (int) n; c++)
            if (maze[n * r + c] == 2) position = n * r + c;
    
    // Translate directions to its impact on array index
    int dir[] = {['N'] = - n, ['E'] = 1, ['W'] = - 1, ['S'] = n};

    // Let's Walk !
    while (*directions != '\0')
    {
        // Go outside the maze border?
        if (position + 1 % n == 0 & *directions == 'E') return "Dead1";
        if (position % n == 0 & *directions == 'W') return "Dead2";
        if (position < n && *directions == 'N') return "Dead3";
        if (position >= n * (n - 1) && *directions == 'S') return "Dead4";
          
        position += dir[*directions];
        
        // Hit any walls?
        if (maze[position] == 1) return "Dead5";
        
        // Finish position?
        if (maze[position] == 3) return "Finish";
        *directions++;
    }
    
    return "Lost";
}
