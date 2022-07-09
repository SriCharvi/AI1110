#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header.h"

int  main(void) //main function begins
{
 
//Mean of Uniform random numbers
printf("%lf\n",mean("uni.dat"));

//Variance of Uniform random numbers
printf("%lf\n",var("uni.dat"));

return 0;
}