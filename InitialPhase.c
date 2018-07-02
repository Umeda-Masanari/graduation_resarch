#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "MT.h"
#include <time.h>

#define WLT 64  //素波の数64–128の間くらい

void InitialPhase(double *theta0) {
  double x = 0.0;
  init_genrand((unsigned)time(NULL));

  for(int i = 0; i < WLT; i++) {
    x = genrand_res53();
    theta0[i] = 2.0 * M_PI * x; //乱数;
    printf("初期位相%f\n", theta0[i]);
  }
}

int main(void) {
  int i;
  double theta0[WLT];

InitialPhase(theta0);

  return 0;
}
