// https://www.codewars.com/kata/52423db9add6f6fc39000354


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_NBR 8

int count_nbr(int **cells, int *rowptr, int *colptr, int row, int col)
{
    int nbr_x[] = { row - 1, row - 1, row - 1,
                    row    ,          row,
                    row + 1, row + 1, row + 1 };
  
    int nbr_y[] = { col - 1, col    , col + 1,
                    col - 1,          col + 1,
                    col - 1, col    , col + 1 };
    int cnt = 0;
  
    for (int i = 0; i < NUMBER_OF_NBR; i++)
    {
        if ( (0 <= nbr_x[i] && nbr_x[i] < *rowptr)
          && (0 <= nbr_y[i] && nbr_y[i] < *colptr) 
          && (cells[nbr_x[i]][nbr_y[i]] == 1) )
          cnt++;
    }
  
    return cnt;
}

int next_cell(int **cells, int *rowptr, int *colptr, int row, int col)
{
    int nbr = count_nbr(cells, rowptr, colptr, row, col);
    return (nbr < 2 || nbr > 3) ? 0 : (cells[row][col] ? 1 : nbr == 3);
}

int **expand(int **cells, int *rowptr, int *colptr)
{
    int **next_gen = calloc(*rowptr + 2, sizeof(int *));
    for (int i = 0; i < *rowptr + 2; i++)
    {
        *(next_gen + i) = calloc(*colptr + 2, sizeof(int));
        memset(*(next_gen + i), 0, (*colptr + 2) * sizeof(int));
    }
    
    for (int i = 1; i < *rowptr + 1; i++)
        for (int j = 1; j < *colptr + 1; j++)
            *(*(next_gen + i) + j) = *(*(cells + (i - 1)) + (j - 1));
    
    *rowptr += 2;
    *colptr += 2;
  
    return next_gen;
}

int any_row(int *n, int *arr)
{
    for (int i = 0; i < *n; i++)
        if (arr[i])
            return 1;
    return 0;
}

int any_col(int **arr, int *rowptr, int col)
{
    for (int row = 0; row < *rowptr; row++)
        if (arr[row][col])
            return 1;
    return 0;
}

void trim(int **cells, int *rowptr, int *colptr)
{
    while (!any_row(colptr, cells[0]))
    {
        for (int row = 0; row < *rowptr - 1; row++)
            for (int col = 0; col < *colptr; col++)
                cells[row][col] = cells[row + 1][col];
        *rowptr -= 1;
    }
    while (!any_row(colptr, cells[*rowptr - 1]))
        *rowptr -= 1;
    while (!any_col(cells, rowptr, 0))
    {
        for (int row = 0; row < *rowptr; row++)
            for (int col = 0; col < *colptr - 1; col++)
                cells[row][col] = cells[row][col + 1];
        *colptr -= 1;
    }
    while (!any_col(cells, rowptr, *colptr - 1))
        *colptr -= 1;
}

int **next_gen(int **cells, int *rowptr, int *colptr)
{
    int **new_cells = expand(cells, rowptr, colptr);
    *rowptr -= 2;
    *colptr -= 2; // Yeah, that's ugly af
    int **old_cells = expand(cells, rowptr, colptr);
    for (int row = 0; row < *rowptr; row++)
        for (int col = 0; col < *colptr; col++)
            new_cells[row][col] = next_cell(old_cells, rowptr, colptr, row, col);
    trim(new_cells, rowptr, colptr);
    return new_cells;
}

char *htmlize(int **, int, int);
int **get_generation(int **cells, int generations, int *rowptr, int *colptr) {
  // Your code here
  // NOTE: Please make a deep copy of the GoL universe and modify that instead
  // of the original universe `cells` passed in because the test cases will
  // `free` the memory allocated by your solution *and* to the original grid
  // which will throw an error otherwise.  Also keep in mind that it is considered
  // best practice to keep your function pure.
  int **test = expand(cells, rowptr, colptr);
  trim(test, rowptr, colptr);
  for (int g = 0; g < generations; g++)
      test = next_gen(test, rowptr, colptr);
  return test;
}
