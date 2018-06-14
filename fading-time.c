#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

#define WLT　64　//素波の数64–128の間くらい
#define dt 0.003 //測定の間隔[s]
#define Freq 2.5e9 //2.5[GHz]帯の周波数

int main(void){
  double *I, *Q, *theta;
  //double N_factor =  //N_factor=正規化係数 は自分で見つける

  double lambda = 299792458/Freq;//真空中の搬送波の波長/周波数　
  double f_D= V/lambda; //最大ドップラー周波数
  int i;
  for (i = 0; i < WLT; i++) {

  }

}
