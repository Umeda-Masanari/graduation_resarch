#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

#define WLT 64  //素波の数64–128の間くらい
#define dt 0.003 //測定の間隔[s]
#define Freq 2.5e9 //2.5[GHz]帯の周波数
#define V (4.8e3 / 3600)  //一般人の歩行速度

/**
*
* setup theta value.
*
* @param {double} *theta
*
*/
void setupAntennaDir(double *theta) {

  for(int i = 0; i < WLT; i++) {
    theta[i] = 360 / WLT * i;
    // printf("%lf \n", theta[i]);
  }
}


int main(void){
  double I = 0, Q = 0, theta[WLT], f, f_s;
  double N_coefficient = sqrt(1.0 / (double)WLT);  //%%%%%%%%N_coefficient=正規化係数 は自分で見つける

printf("%f\n",N_coefficient);

  double lambda = 3.0e8 / Freq; //真空中の搬送波の波長/周波数　
  double f_D= V / lambda; //最大ドップラー周波数

  setupAntennaDir(theta);

  for (int i = 0; i < WLT; i++) {
    f_s = f_D * cos(theta[i]);
    f = 2.0 * M_PI * f_s * (double)dt;

    I += cos( f + theta[i]) * N_coefficient;
    Q += sin( f + theta[i]) * N_coefficient;
  }

  printf("I相%lf\t Q相%lf\n", I, Q);

  return 0;
}
