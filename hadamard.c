#include<stdio.h>
#include "p.h"

unsigned msb(unsigned n){
  n|=n>>1; n|=n>>2; n|=n>>4;
  n|=n>>8; n|=n>>16;
  return n^(n>>1);
}

int hadamard_core(int y,int x){
  int m,n;
  if( x== 0 || y == 0)return  1;
  if(x == 1 && y == 1)return -1;
  n = (m = msb(x|y))-1;
  m = (m <= x && m <= y)?-1:1;
  return m * hadamard_core(y&n,x&n);
}
// int vec[y][x];
// hadmard(8, vec); -> vec[8][8]
/*
                  y
                  |
                  v  0  1  2  3  ->x
    vec[0][0] <-  0 1, 1, 1, 1  -> vec[0][3]
    vec[1][0] <-  1 1,-1, 1,-1  -> vec[1][3]
                  2 1, 1,-1,-1
                  3 1,-1,-1, 1
*/
void hadamard(int size, int vec[size][size]) {
  for(int y = 0; y < size; y++) {
    for(int x = 0; x < size; x++) {
      vec[y][x] = hadamard_core(y, x);
    }
  }
}
