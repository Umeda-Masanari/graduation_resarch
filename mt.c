#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "MT.h"

int main(void){
    double x = 0.0;

    init_genrand((unsigned)time(NULL));
    x = genrand_res53();
printf("%f",x);




    return(0);
}
