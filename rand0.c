#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "MT.h"

int main(void){
    double x,y;
    double sn;
    double n;
    double noise = 0.0;
    int i,k;
    int max=2048;

    FILE *fp;         // 出力ストリーム

      fp = fopen("noise.csv", "w");  // ファイルを書き込み用にオープン(開く)
      if (fp == NULL) {          // オープンに失敗した場合
        printf("cannot open\n");         // エラーメッセージを出して
        exit(1);                         // 異常終了
      }

    init_genrand((unsigned)time(NULL));
for(i=0;i<max;i++){
    n = 0.5*pow(10.0,(-1.0/10.0*sn));
    y = genrand_res53();
    x = 0.0;
    while (x == 0.0) {
      x = genrand_res53();
    }
    y = genrand_res53();

    noise = sqrt(-2.0*n*log(x))*cos(2.0*M_PI*y);

     fprintf(fp, "%f\n",noise); // ファイルに書く
}
     fclose(fp);          // ファイルをクローズ(閉じる)

printf("%f/n",noise);




    return(0);
}
