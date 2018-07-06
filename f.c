#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"
#include "MT.h"
#include "p.h"
#include <time.h>

#define WLT 64  //素波の数64–128の間くらい
#define Freq 2.5e9 //2.5[GHz]帯の周波数
#define V (4.8e3 / 3600)  //一般人の歩行速度
#define Dt 1e-5 // dtの刻み幅(10μs)
#define times 10e4 //計測時間
#define VEC_SIZ 64 // hadamard size
/**
*
* setup theta value.
*
* @param {double} *theta
*
*/
void InitialPhase(double *theta0) {
  double x = 0.0;
  init_genrand((unsigned)time(NULL));

  for(int i = 0; i < WLT; i++) {
    x = genrand_res53();
    theta0[i] = 2.0 * M_PI * x; //乱数;
    //printf("初期位相%f\n", theta0[i]);
  }
}

int main(void){
  double theta0[WLT], f, dt;
  double I[(int)times] = {}, Q[(int)times] = {};
  double N_coefficient = sqrt(1.0 / (double)WLT);  //%%%%%%%%N_coefficient=正規化係数 は自分で見つける

  int vec[VEC_SIZ][VEC_SIZ];
  int vsiz = VEC_SIZ;

  hadamard(vsiz, vec);

//printf("%f\n",N_coefficient);

  double lambda = 3.0e8 / Freq; //真空中の搬送波の波長/周波数　
  double f_D= V / lambda; //最大ドップラー周波数

  InitialPhase(theta0);

  FILE *fp;         // 出力ストリーム

    fp = fopen("I相Q相.csv", "w");  // ファイルを書き込み用にオープン(開く)
    if (fp == NULL) {          // オープンに失敗した場合
      printf("cannot open\n");         // エラーメッセージを出して
      exit(1);                         // 異常終了
    }


  for (int k = 0; k < 10e4; k++) {
     dt = k * Dt; //時間は1μs秒刻みの10秒まで


     for (int i = 0; i < WLT; i++) {
        f = 2.0 * M_PI * f_D * cos(2.0 * M_PI / (double)WLT * (double)i) * dt;
//printf("%f\n",dt );
        I[k] += cos( f + theta0[i]) * N_coefficient;
        Q[k] += sin( f + theta0[i]) * N_coefficient;
    }
    fprintf(fp, "%f\t %lf\n", dt, I[k]/*, Q[k]*/); // ファイルに書く
 }
      fclose(fp);          // ファイルをクローズ(閉じる)

  return 0;
}
