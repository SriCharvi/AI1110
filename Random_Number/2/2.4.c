#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header.h"

int  main(void) //main function begins
{
//Mean of guassian
printf("Mean is %lf\n",mean("gau.dat"));

//Variance of guassian
printf("Variance is %lf\n",var("gau.dat"));
return 0;
}
