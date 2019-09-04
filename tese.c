#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
// #include "mode.h"

// static int sum(char *num)
// {
//     u_int32_t leak_sum;
//     leak_sum = num[0] * PRECISION1 + num[1] * PRECISION2 + num[2] * PRECISION3 + num[3] * PRECISION4 + num[4] * PRECISION5 + num[5] * PRECISION6 + num[6] * PRECISION7 + num[7] * PRECISION8 + num[8] * PRECISION9;
//     return leak_sum;
// }

int main(void)
{
    // u_int32_t k;
    // int num[9], i;
    u_int32_t j;

    scanf("%d", &j);
    printf("%#X\n", j);

    // k = j * 1000000000;
    // for (i = 0; i < 9; i++)
    // {
    //     switch (i)
    //     {
    //     case 0:
    //         num[i] = k / 100000000;
    //         break;
    //     case 1:
    //         num[i] = k / 10000000 % 10;
    //         break;
    //     case 2:
    //         num[i] = k / 1000000 % 100 % 10;
    //         break;
    //     case 3:
    //         num[i] = k / 100000 % 1000 % 100 % 10;
    //         break;
    //     case 4:
    //         num[i] = k / 10000 % 10000 % 1000 % 100 % 10;
    //         break;
    //     case 5:
    //         num[i] = k / 1000 % 100000 % 10000 % 1000 % 100 % 10;
    //         break;
    //     case 6:
    //         num[i] = k / 100 % 1000000 % 100000 % 10000 % 1000 % 100 % 10;
    //         break;
    //     case 7:
    //         num[i] = k / 10 % 10000000 % 100000 % 10000 % 1000 % 100 % 10;
    //     case 8:
    //         num[i] = k % 100000000 % 10000000 % 100000 % 10000 % 1000 % 100 % 10;
    //         break;
    //     }
    //     printf("%d\n", num[i]);
    // }
    // k = sum(num);
    // printf("%#x\n", k);
}