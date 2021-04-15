/**
 *                                    DISCLAIMER
 * This code is really ugly, it needs to be revised for more clarity and understandability.
 * TODO: Lowest adjacent to clue 2
 **/

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 4

struct cell
{
    int possibility_count;
    int possibilities[BOARD_SIZE];
};

struct board
{
    int cell_count;
    struct cell cells[BOARD_SIZE * BOARD_SIZE];
};

int index_of(int arrc, int *arrv, int n)
{
    for (int i = 0; i < arrc; i++)
        if (arrv[i] == n)
            return i;
    return -1;
}

void initialize_cell(struct cell *cell)
{
    cell->possibility_count = BOARD_SIZE;
    for (int i = 1; i <= BOARD_SIZE; i++)
        cell->possibilities[i - 1] = i;
}

void initialize_board(struct board *board)
{
    board->cell_count = BOARD_SIZE * BOARD_SIZE;
    for (int i = 0; i < board->cell_count; i++)
    {
        struct cell c;
        initialize_cell(&c);
        
        board->cells[i] = c;
    }
}

void remove_possibility(struct cell *cell, int n)
{
    int start = index_of(cell->possibility_count, cell->possibilities, n);
    if (start != -1)
    {
        for (int i = start; i < cell->possibility_count; i++)
            cell->possibilities[i] = cell->possibilities[i + 1];
      
        cell->possibility_count--;
    }
}

int clue_index_on_board(int clue)
{
    if (clue < BOARD_SIZE) // Top clues
        return clue;
  
    else if (clue < 2 * BOARD_SIZE) // Right clues
        return clue - 1 + (clue % BOARD_SIZE) * (BOARD_SIZE - 1);
  
    else if (clue < 3 * BOARD_SIZE) // Bottom clues
        return BOARD_SIZE * BOARD_SIZE - clue + 2 * BOARD_SIZE - 1;
  
    else // Left clues
        return (4 * BOARD_SIZE - clue - 1) * BOARD_SIZE;
}

int is_clue_on_row(int clue)
{
    if ( (BOARD_SIZE <= clue && clue < 2 * BOARD_SIZE) ||
         (3 * BOARD_SIZE <= clue) )
        return 1;
    return 0;
}

void edge_clue_initialization(struct board *board, int *clues)
{
    for (int i = 0; i < board->cell_count; i++)
    {
        if (clues[i] == 1) // Adjacent cell resolved to BOARD_SIZE
            for (int p = 1; p < BOARD_SIZE; p++)
                remove_possibility(&(board->cells[clue_index_on_board(i)]), p);
        else if (clues[i] == BOARD_SIZE) // row/col resolved to {1..N}
        {
            if (is_clue_on_row(i))
            {
                if (i >= 3 * BOARD_SIZE) // Left side clue
                {
                    for (int d = 0, keep = 1; d < BOARD_SIZE; d++, keep++)
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != keep)
                                remove_possibility(&(board->cells[clue_index_on_board(i) + d]), rm);
                }
                else // Right side clue
                {
                    for (int d = 0, keep = 1; -d < BOARD_SIZE; d--, keep++)
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != keep)
                                remove_possibility(&(board->cells[clue_index_on_board(i) + d]), rm);
                }
            }
            else 
            {
                if (i < BOARD_SIZE) // Top side clue
                {
                    for (int d = 0, keep = 1; d < BOARD_SIZE; d++, keep++)
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != keep)
                                remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE * d]), rm);
                }
                else // Bot side clue
                {
                    for (int d = 0, keep = 1; d < BOARD_SIZE; d++, keep++)
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != keep)
                                remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE * d]), rm);
                }
            }
        }
        else
        {
            if (is_clue_on_row(i))
            {
                if (i >= 3 * BOARD_SIZE) // Left side clue
                {
                    for (int d = 0; d < BOARD_SIZE; d++)
                        for (int cross = BOARD_SIZE - clues[i] + 2 + d; cross <= BOARD_SIZE; cross++)
                            remove_possibility(&(board->cells[clue_index_on_board(i) + d]), cross);
                }
                else // Right side clue
                {
                    for (int d = 0; -d < BOARD_SIZE; d--)
                        for (int cross = BOARD_SIZE - clues[i] + 2 - d; cross <= BOARD_SIZE; cross++)
                            remove_possibility(&(board->cells[clue_index_on_board(i) + d]), cross);
                }
            }
            else
            {
                if (i < BOARD_SIZE) // Top side clue
                {
                    for (int d = 0, keep = 1; d < BOARD_SIZE; d++, keep++)
                        for (int cross = BOARD_SIZE - clues[i] + 2 + d; cross <= BOARD_SIZE; cross++)
                            remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE * d]), cross);
                }
                else // Bottom side clue
                {
                    for (int d = 0, keep = 1; d < BOARD_SIZE; d++, keep++)
                        for (int cross = BOARD_SIZE - clues[i] + 2 + d; cross <= BOARD_SIZE; cross++)
                            remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE * d]), cross);
                }
            }
        }
    }
}

void advanced_strat(struct board *board, int *clues)
{
    for (int i = 0; i < board->cell_count; i++)
    {
        if (clues[i] == 2) // TODO: Lowest sc adjacent to clue 2
        {
            if (is_clue_on_row(i))
            {
                if (i >= 3 * BOARD_SIZE) // Left side clue
                {
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE - 1].possibilities[0] == BOARD_SIZE) // Highest sc far opposite clue 2 => Second highest sc next to clue 2
                    {
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != BOARD_SIZE - 1)
                                remove_possibility(&(board->cells[clue_index_on_board(i)]), rm);
                    }
                    
                    // Second highest sc in second square from clue 2 => Impossible
                    remove_possibility(&(board->cells[clue_index_on_board(i) + 1]), BOARD_SIZE - 1);
                  
                    // 2nd Highest / Highest / ???? < [2] => 2nd Highest / Highest / ... / 4th Highest / 3rd Highest < [2]
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE - 1].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 2].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 1].possibility_count == 1)
                    {
                        for (int keep = BOARD_SIZE - 2, distance = 0; keep >= 1; keep--, distance++)
                        {
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) + distance]), rm);
                        }
                    }
                  
                    // 4x4: [2] > ? / ? / 4 / ? => Adjacent cell to clue 2 can't be 1
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 2].possibilities[0] == 4)
                        remove_possibility(&(board->cells[clue_index_on_board(i)]), 1);
                  
                    // 4x4: [2] > 2 / ? / 4 / ? ==> 2 / 1 / 4 / 3
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 2].possibilities[0] == 4 &&
                        board->cells[clue_index_on_board(i)].possibilities[0] == 2 &&
                        board->cells[clue_index_on_board(i)].possibility_count == 1)
                    {
                        remove_possibility(&(board->cells[clue_index_on_board(i) + 1]), 3);
                        remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE - 1]), 1);
                    }
                    
                }
                else // Right side clue
                {
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE + 1].possibilities[0] == BOARD_SIZE) // Highest sc far opposite clue 2 => Second highest sc next to clue 2
                    {
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != BOARD_SIZE - 1)
                                remove_possibility(&(board->cells[clue_index_on_board(i)]), rm);
                    }
                  
                    // Second highest sc in second square from clue 2 => Impossible
                    remove_possibility(&(board->cells[clue_index_on_board(i) - 1]), BOARD_SIZE - 1);
                  
                    // 2nd Highest / Highest / ???? < [2] => 2nd Highest / Highest / ... / 4th Highest / 3rd Highest < [2]
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE + 1].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 2].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 1].possibility_count == 1)
                    {
                        for (int keep = BOARD_SIZE - 2, distance = 0; keep >= 1; keep--, distance++)
                        {
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) - distance]), rm);
                        }
                    }
                    
                    // 4x4: [2] > ? / ? / 4 / ? => Adjacent cell to clue 2 can't be 1
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 2].possibilities[0] == 4)
                        remove_possibility(&(board->cells[clue_index_on_board(i)]), 1);
                    
                    // 4x4: [2] > 2 / ? / 4 / ? ==> 2 / 1 / 4 / 3
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 2].possibilities[0] == 4 &&
                        board->cells[clue_index_on_board(i)].possibilities[0] == 2 &&
                        board->cells[clue_index_on_board(i)].possibility_count == 1)
                    {
                        remove_possibility(&(board->cells[clue_index_on_board(i) - 1]), 3);
                        remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE + 1]), 1);
                    }
                }
            }
            else
            {
                if (i < BOARD_SIZE) // Left side clue
                {
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE) // Highest sc far opposite clue 2 => Second highest sc next to clue 2
                    {
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != BOARD_SIZE - 1)
                                remove_possibility(&(board->cells[clue_index_on_board(i)]), rm);
                    }
                  
                    // 2nd Highest / Highest / ???? < [2] => 2nd Highest / Highest / ... / 4th Highest / 3rd Highest < [2]
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)].possibility_count == 1)
                    {
                        for (int keep = BOARD_SIZE - 2, distance = 0; keep >= 1; keep--, distance++)
                        {
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE * distance]), rm);
                        }
                    }
                    
                    // 4x4: [2] > ? / ? / 4 / ? => Adjacent cell to clue 2 can't be 1
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == 4)
                        remove_possibility(&(board->cells[clue_index_on_board(i)]), 1);
                    
                    // 4x4: [2] > 2 / ? / 4 / ? ==> 2 / 1 / 4 / 3
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == 4 &&
                        board->cells[clue_index_on_board(i)].possibilities[0] == 2 &&
                        board->cells[clue_index_on_board(i)].possibility_count == 1)
                    {
                        remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE]), 3);
                        remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)]), 1);
                    }
                  
                }
                else // Right side clue
                {
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE) // Highest sc far opposite clue 2 => Second highest sc next to clue 2
                    {
                        for (int rm = 1; rm <= BOARD_SIZE; rm++)
                            if (rm != BOARD_SIZE - 1)
                                remove_possibility(&(board->cells[clue_index_on_board(i)]), rm);
                    }
                  
                    // 2nd Highest / Highest / ???? < [2] => 2nd Highest / Highest / ... / 4th Highest / 3rd Highest < [2]
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)].possibility_count == 1)
                    {
                        for (int keep = BOARD_SIZE - 2, distance = 0; keep >= 1; keep--, distance++)
                        {
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE * distance]), rm);
                        }
                    }
                    
                    // 4x4: [2] > ? / ? / 4 / ? => Adjacent cell to clue 2 can't be 1
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == 4)
                        remove_possibility(&(board->cells[clue_index_on_board(i)]), 1);
                  
                    // 4x4: [2] > 2 / ? / 4 / ? ==> 2 / 1 / 4 / 3
                    if (BOARD_SIZE == 4 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == 4 &&
                        board->cells[clue_index_on_board(i)].possibilities[0] == 2 &&
                        board->cells[clue_index_on_board(i)].possibility_count == 1)
                    {
                        remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE]), 3);
                        remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)]), 1);
                    }
                }
            }
        }
      
        else if (clues[i] == 3 && BOARD_SIZE == 4) // WARNING : Only 4x4
        {
            // 3 / 4 / 12 / 12 < [3] => 3 / 4 / 2 / 1 < [3]
            if (is_clue_on_row(i))
            {
                if (i >= 12)
                {
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE - 1].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 2].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE - 1].possibility_count == 1)
                    {
                        for (int keep = 1, distance = 0; keep <= 2; keep++, distance++)
                        {
                            
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) + distance]), rm);
                            
                        }
                    }
                }
                else
                {
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE + 1].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 2].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE + 1].possibility_count == 1)
                    {
                        for (int keep = 1, distance = 0; keep <= 2; keep++, distance++)
                        {
                            
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) - distance]), rm);
                            
                        }
                    }
                }
            }
            else
            {
                if (i <= 3)
                {
                    if (board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) + BOARD_SIZE * (BOARD_SIZE - 1)].possibility_count == 1)
                    {
                        for (int keep = 1, distance = 0; keep <= 2; keep++, distance++)
                        {
                            
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) + BOARD_SIZE * distance]), rm);
                            
                        }
                    }  
                }
                else
                {
                    if (board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)].possibilities[0] == BOARD_SIZE - 1 &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 2)].possibilities[0] == BOARD_SIZE &&
                        board->cells[clue_index_on_board(i) - BOARD_SIZE * (BOARD_SIZE - 1)].possibility_count == 1)
                    {
                        for (int keep = 1, distance = 0; keep <= 2; keep++, distance++)
                        {
                            
                            for (int rm = 1; rm <= BOARD_SIZE; rm++)
                                if(rm != keep)
                                    remove_possibility(&(board->cells[clue_index_on_board(i) - BOARD_SIZE * distance]), rm);
                            
                        }
                    }  
                }
            }
        }
        
    }
};

void constraint_propagation(struct board *board, int *clues) // Start from resolved cell & remove value on row/col
{
    for (int i = 0; i < board->cell_count; i++)
    {
        if (board->cells[i].possibility_count == 1)
        {
            int col = i % 4, row = i / 4;
            for (int r = 0; r < BOARD_SIZE; r++)
                if (row * 4 + r != i)
                    remove_possibility(&(board->cells[row * 4 + r]), board->cells[i].possibilities[0]);
            for (int c = 0; c < BOARD_SIZE; c++)
                if (col + 4 * c != i)
                    remove_possibility(&(board->cells[col + 4 * c]), board->cells[i].possibilities[0]);
        }
    }
}

void process_of_elimination(struct board *board, int *clues) // Value no longer present in any other cells in either row/col
{
    for (int i = 0; i < board->cell_count; i++)
    {
        if (board->cells[i].possibility_count != 1)
            for (int p = 0; p < board->cells[i].possibility_count; p++)
            {
              
                int is_alone_row = 1, is_alone_col = 1;
              
                int col = i % BOARD_SIZE, row = i / BOARD_SIZE;
                for (int r = 0; r < BOARD_SIZE; r++)
                {
                    if (row * BOARD_SIZE + r != i)
                        for (int j = 0; j < board->cells[row * BOARD_SIZE + r].possibility_count; j++)
                            if (board->cells[row * BOARD_SIZE + r].possibilities[j] == board->cells[i].possibilities[p])
                                is_alone_row = 0;
                }
                for (int c = 0; c < BOARD_SIZE; c++)
                {
                    if (col + BOARD_SIZE * c != i)
                        for (int j = 0; j < board->cells[col + BOARD_SIZE * c].possibility_count; j++)
                            if (board->cells[col + BOARD_SIZE * c].possibilities[j] == board->cells[i].possibilities[p])
                                is_alone_col = 0;
                }
              
                if (is_alone_row || is_alone_col)
                {
                    printf("IS ALONE %d %d\n", i, board->cells[i].possibilities[p]);
                    int j = 0;
                    const int keep = board->cells[i].possibilities[p];
                    while (j < board->cells[i].possibility_count && board->cells[i].possibility_count != 1)
                    {
                        if (board->cells[i].possibilities[j] != keep)
                        {
                            const int n = board->cells[i].possibilities[j];
                            printf("%d ", n);
                            remove_possibility(&(board->cells[i]), n);
                            printf("%d\n", n);
                            j = 0;
                        }
                        else
                            j++;
                    }
                }
            }
    }
}
  
void print_board(struct board b, int *clues)
{
    for (int i = 0; i < BOARD_SIZE; i++)
        printf("\t[%d]", clues[i]);
    printf("\n");
    
    for (int s = 0; s < b.cell_count; s += BOARD_SIZE)
    {
        printf(" [%d]\t", clues[4 * BOARD_SIZE - 1 - s / BOARD_SIZE]);
        for (int i = s; i < s + BOARD_SIZE; i++)
        {
            for (int j = 0; j < b.cells[i].possibility_count; j++)
                printf("%d", b.cells[i].possibilities[j]);
            printf("\t");
        }
        printf("[%d]", clues[BOARD_SIZE + s / BOARD_SIZE]);
        printf("\n");
    }
  
    for (int i = 3 * BOARD_SIZE - 1; i >= 2 * BOARD_SIZE; i--)
        printf("\t[%d]", clues[i]);
    printf("\n");
    
}

int is_completed(struct board board)
{
    for (int i = 0; i < board.cell_count; i++)
        if (board.cells[i].possibility_count != 1)
            return 0;
    return 1;
}

/*
void brute_force(struct board *board, int *clues)
{
    for (int i = 0; i < board->cell_count)
    {
        if (clues[i] && clues[i] != 1 && clues[i] != BOARD_SIZE)
        {
            
        }
    }
}
*/

int** SolvePuzzle(int *clues) 
{
    printf("\n[INITIAL]\n");
    struct board skyscrapers;
    initialize_board(&skyscrapers);
  
    print_board(skyscrapers, clues);
  
    edge_clue_initialization(&skyscrapers, clues);
    printf("--ECI--\n");
    print_board(skyscrapers, clues);
    
    advanced_strat(&skyscrapers, clues);
    printf("--AS--\n");
    print_board(skyscrapers, clues);
  
    constraint_propagation(&skyscrapers, clues);
    printf("--CP--\n");
    print_board(skyscrapers, clues);
  
    process_of_elimination(&skyscrapers, clues);
    printf("--POE--\n");
    print_board(skyscrapers, clues);
    
    int max = 4, k = 0;
    while (!is_completed(skyscrapers) && k < max)
    {
        k++;
        advanced_strat(&skyscrapers, clues);
        printf("--AS--\n");
        print_board(skyscrapers, clues);
        
        constraint_propagation(&skyscrapers, clues);
        printf("--CP--\n");
        print_board(skyscrapers, clues);
  
        process_of_elimination(&skyscrapers, clues);
        printf("--POE--\n");
        print_board(skyscrapers, clues);
    }
    
    if (is_completed(skyscrapers))
    {
        int **result = calloc(BOARD_SIZE, sizeof(int *));
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            result[i] = calloc(BOARD_SIZE, sizeof(int));
            for (int j = 0; j < BOARD_SIZE; j++)
                result[i][j] = skyscrapers.cells[BOARD_SIZE * i + j].possibilities[0];
        }

        return result;
    }
    return NULL;
}
