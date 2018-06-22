#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
<<<<<<< HEAD
=======
#include "MT.h"
#include <time.h>
>>>>>>> test

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
<<<<<<< HEAD
void setupAntennaDir(double *theta) {

  for(int i = 0; i < WLT; i++) {
    theta[i] = 360 / WLT * i;
    // printf("%lf \n", theta[i]);
  }
}


int main(void){
  double I = 0, Q = 0, theta[WLT], omega, k;
  double N_coefficient = sqrt(1.0 / (double)WLT);  //%%%%%%%%N_coefficient=正規化係数 は自分で見つける

printf("%f\n",N_coefficient);

  double lambda = 3.0e8 / Freq; //真空中の搬送波の波長/周波数　
  double f_D= V / lambda; //最大ドップラー周波数

  setupAntennaDir(theta);

  for (int i = 0; i < WLT; i++) {
    k = f_D * cos(2.0 * M_PI * (double)i / (double)WLT);
    omega = 2.0 * M_PI * k * (double)dt;
    I += cos(omega + theta[i]); //* N_coefficient;
    Q += sin(omega + theta[i]); //* N_coefficient;
  }

  printf("%lf\t %lf\n", I, Q);

=======
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


  for (int k = 0; k < 100; k++) {
     t = k * 10e6; //時間は1μs秒刻みの10秒まで

       for (int i = 0; i < WLT; i++) {
        f = 2.0 * M_PI * f_D * cos(2.0*M_PI/(double)WLT*(double)i) * (double)dt * (double)t ;
      }
}

        I += cos( f + theta0) * N_coefficient;
        Q += sin( f + theta0) * N_coefficient;

  printf("I相%lf\t Q相%lf\n", I, Q);

>>>>>>> test
  return 0;
}
