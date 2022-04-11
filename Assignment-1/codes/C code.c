/*
  ICSE 2019 Grade 10
Question 10(b)
Name: Sri Charvi Salapu
Roll number: BT21BTECH11008
 */

//To find the height of the tower
#include <stdio.h>
#include <math.h>
#define PI 3.142
int main() {
 float h,tanA,tanB;   
   
    tanA=tan(45*(PI/180));
    tanB=tan(60*(PI/180));
    
    
   h = tanA*((tanB*20)/(tanB-1));
    printf("Height of the tower is %.2fm",h);
 
    
   
    return 0;
}