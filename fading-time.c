#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "MT.h"
#include <time.h>

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
void InitialPhase(double theta0) {
  double x = 0.0;
  init_genrand((unsigned)time(NULL));
  x = genrand_res53();
    theta0 = 2.0 * M_PI * x; //乱数;
    printf("初期位相%f\n",theta0 );
}




int main(void){
  double I = 0, Q = 0,theta0, f, t;
  double N_coefficient = sqrt(1.0 / (double)WLT);  //%%%%%%%%N_coefficient=正規化係数 は自分で見つける

//printf("%f\n",N_coefficient);

  double lambda = 3.0e8 / Freq; //真空中の搬送波の波長/周波数　
  double f_D= V / lambda; //最大ドップラー周波数

  InitialPhase(theta0);


  for (int k = 0; k < 200; k++) {
     t = k / 10; //時間は0.1秒刻みの20秒まで

       for (int i = 0; i < WLT; i++) {
        f = 2.0 * M_PI * f_D * cos(2.0*M_PI/(double)WLT*(double)i) * (double)dt * (double)t ;
      }
}

        I += cos( f + theta0) * N_coefficient;
        Q += sin( f + theta0) * N_coefficient;

  printf("I相%lf\t Q相%lf\n", I, Q);

  return 0;
}
