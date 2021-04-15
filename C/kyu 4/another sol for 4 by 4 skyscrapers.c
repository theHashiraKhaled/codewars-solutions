//it's actually not my solution but I found it interesting

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

int fac(int n){  return n ? n * fac(n-1) : 1; }

int * genPerm(int n, int N){
  n--;
  int * base = calloc (N, sizeof(int));
  for (int i = 0; i < N; i++){ base[i] = i+1; }

  for (int i = 0; i < N-1; i++){
    int dec = fac(N-1-i);
    if (n >= dec) { //swap
      int buf       = base[i];
      base[i]       = base[i+n/dec];
      base[i+n/dec] = buf;
    }
    n %= dec;
  }
  return base;
}

void init(int ** permutations, int ** M, int N){ //allocation
  for (int i = 0; i < fac(N); i++){
    permutations[i] = genPerm(i+1, N);
  }
  for (int i = 0; i < N; i++) 
    M[i] = calloc(N, sizeof(int));
}

int vision(int n, int dir, int** M, int length){
  int v, h;
  switch (dir) {
    case -1: v=n; h=length-1; break;
    case 1: v=n; h=0; break;
    case -2: v=length-1; h=n; break;
    case 2: v=0; h=n; break;
  }
  int count =1;
  int biggest = M[v][h];
  for (int i = 0; i < length; i++){
    if(M[v][h] > biggest) {count++; biggest = M[v][h];}
    v += dir/2;
    h += dir%2;
  }
  return count;
}

bool validPlacement(int ** M, int * hints, int toV, int N){
  for (int i = 0; i < N; i++)                                            //check for incorrect sudoku caused by current line
    for (int j = 0; j < toV; j++)
      if (M[j][i] == M[toV][i]) return false;
  if ( ( hints[4*N-toV-1] && vision(toV, 1,M,N) != hints[4*N-toV-1] ) || //check for incorrect hints at sides of current line
       ( hints[  N+toV  ] && vision(toV,-1,M,N) != hints[  N+toV  ] ) ) return false;
  if (toV == N-1) for (int i = 0; i < N; i++){                           //check for incorrect hints at top and bottom only if matrix full
      if ( ( hints[   i   ] && vision(i, 2,M,N) != hints[   i    ] )|| 
           ( hints[3*N-i-1] && vision(i,-2,M,N) != hints[3*N -i-1] ) ) return false;
  }
  return true;
}

bool solve(int**M, int N, int ** permutations, int * clues, int n, int i){     //backtracking
  if (n >= N)      return true;
  if (i >= fac(N)) return false;
  M[n] = permutations[i];
  if(!validPlacement(M, clues, n, N))           return solve(M, N, permutations, clues, n, i+1);
  if(!solve(M, N, permutations, clues, n+1, 0)) return solve(M, N, permutations, clues, n, i+1);
  return true;
}

int **SolvePuzzle(int *clues) { 
  int N=4;                                                //4x4 skyscraper ;)
  int ** M = malloc(N*sizeof(int*));
  int ** permutations = malloc(fac(N) * sizeof(int*));
  init(permutations, M, N);
  solve(M, N, permutations, clues, 0, 0);                 //recursive, backtracking solve-function
  return M;
}
